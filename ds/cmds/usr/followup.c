// followup.c
// last modify: alick@ds 2003-03-26 ,add wiz_only chk
// Luky
#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit F_DBASE;
int help(object);
void create() { seteuid(getuid()); set("no_clean_up",1); }
void done_post(object me,object board,mapping note,string text)
{
  string myid;
  mapping *notes;
	int c , tp;
  string sigfn,sig,id;

  myid = board->query("board_id");
  id = me->query("id");
  sigfn = sprintf ("%ssignature/%s/%s.sig",DATA_DIR,id[0..0],id);
        if( board->query("wiz_only") && !wizardp(me) )
	{
                write("此留言板只限巫師留言。\n");
		return;
	}
        tp = me->query("level")*3+5;
        if( me->query("talk_point") < (tp/3) ) 
        {
                write("你的談話點數不夠喔，發表文章需要用"+(tp/3)+"點。\n");
                return;
        }
        if( !wizardp(me) ) me->add("talk_point", -(tp/3));

  if (sig = read_file (sigfn))
    note["msg"] = text + "\n--\n"+sig+NOR;
  else
    note["msg"] = text+NOR;

  notes = board->query("notes");
  if ( !pointerp(notes) || !sizeof(notes) )
    notes = ({ note });
  else
    notes += ({ note });

  // Truncate the notes if maximum capacity exceeded.
  c = board->BOARD_CAPACITY;
  if (sizeof(notes) > c)
    notes = notes[c / 2 .. c];

  board->set("notes",notes);
  tell_object(me,"留言完畢。\n");

  // Keep track which post we were reading last time.
/*  if ( !mapp(last_read_time) )
    me->set("board_last_read",([ myid: note["time"] ]) );
  else if (undefinedp(last_read_time[myid]) || note["time"] >
    last_read_time[myid] )
  {
    last_read_time[myid] = note["time"];
  }
*/

  board->save();
  return;
}

void ed_exit()
{
  object board;
  mapping note;
  string fn,buf;
  string sigfn,sig,myid;

  board = this_player()->query_temp("post/board");
  note = this_player()->query_temp("post/note");
  fn = this_player()->query_temp("post/fn");
  this_player()->set_temp("post",0);

  myid = this_player()->query("id");
  sigfn = sprintf ("%ssignature/%s/%s.sig",DATA_DIR,myid[0..0],myid);
  if (sig = read_file (sigfn))
    buf = read_file(fn) + "\n--\n" + sig;
  else
    buf = read_file(fn);

  rm (fn);
  done_post (this_player(),board,note,buf);
  buf = 0;
}
/*
int to_post(string yn,object me,object board,mapping note,string note1)
{
  if( yn =="y") me->set_temp("halt_msg_in_edit",1);
  else me->set_temp("halt_msg_in_edit",0);
  me->edit ( (: done_post,me,board,note :),note1 );
  return 1;

} 
*/
int main(object me,string arg)
{
  object board;
  mapping *notes,note;
  int num,count,end;
  string note1,note2,*tmp,tmp2="";

  if (!arg) return 0;
  if (!board = present("board",environment(me)))
    return 0;

  if ( !sscanf(arg,"%d",num) ) return help(me);

  // get notes
  notes = board->query("notes");
  if ( num < 1 || num > sizeof(notes) ) return notify_fail("沒有這張留言。\n");
  num--;
  // note 是要編的信，notes 是板面上的信
  // note1 是要回的信的內容，也就是舊信內容,
  // note2 則是改 note1 的暫時信的內容
  note = allocate_mapping(4);
  note2 = (string)notes[num]["title"];
  note2 = replace_string(note2,"●","");
  note2 = replace_string(note2,"回覆:","");
  note1 = "回覆:"+note2;
  note["title"] = note1;
  note["author"] = me->query("name")+"("+getuid(me)+")";
  note["time"] = time();
  note2 = sprintf (" %s        [%s]%s的高見:\n%s\n%s",
                notes[num]["title"]+"",
                ctime(notes[num]["time"])[4..9]+"",
                notes[num]["author"]+"",
                "=============================================================",
                notes[num]["msg"]+"");
  note2 = replace_string(note2,CYN,"");
  note2 = replace_string(note2,NOR,"");
  note2 = ":"+note2;
  //note1 = replace_string(note2,"\n",CYN+"\n: ");
  note1 = replace_string(note2,"\n","\n: ");
  note1 = note1[0..<3];
  note1 = note1+"\n";

  tmp = explode(note1,"\n");
  note1 = "";
  //只取10行
  end=member_array(": --",tmp);
  if(end==-1) end=sizeof(tmp)-1;
  else end-=1;

  for (num=end; num >= 0; num--)
  {
    if(tmp[num] == ": ") continue;  //空白引言
    if(strsrch(tmp[num],": ") == 0 )
    {
      if(strsrch(tmp[num],"=============================================================") == -1
         && strsrch(tmp[num],"的高見") == -1
         && count > 24
      ) continue;
      count ++;
      tmp2 = tmp[num]+"\n"+tmp2;
    }
    else tmp2 = tmp[num]+"\n"+tmp2;
  }
  tmp = 0;
  note1 = CYN+tmp2;
  note1 = note1+NOR+"\n";
  
  me->edit ( (: done_post,me,board,note :),note1 );
  return 1;
  
//  write("您要在編輯時暫停所有訊息(包括被攻擊)的接收嗎?(y/n) ");
//  return input_to( (: to_post :), me,board,note,note1 );

}

int help(object me)
{
  write(@HELP
指令格式 : followup <編號>

指令說明 :  本命令用來回應別人的留言。

	如: >followup 10  (表示回應第10篇留言)

相關指令: post , signature 。
HELP
    );
    return 1;
}
