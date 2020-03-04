// post.c
// last modify: alick@ds 2003-03-26 ,add wiz_only chk

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit F_DBASE;
int help(object);
//int to_post(string yn,object ob,string arg,object board);
void create() { seteuid(getuid()); set("no_clean_up",1); }
void done_post(object me,object board,mapping note,string text)
{
  string myid;
  mapping *notes;
	int c, tp;
  string sigfn,sig,id;

  seteuid(ROOT_UID);
  myid = board->query("board_id");
  id = me->query("id");
  if( id == "guest" )
      return 0;
	if( board->query("wiz_only") && !wizardp(me) )
	{
		write("���d���O�u���Ův�d���C\n");
		return;
	}
	tp = me->query("level")*3+5;
        if( me->query("talk_point") < (tp/3) ) 
	{
		write("�A���͸��I�Ƥ�����A�o���峹�ݭn��"+(tp/3)+"�I�C\n");
		return;
	}
	if( !wizardp(me) ) me->add("talk_point", -(tp/3));
  sigfn = sprintf ("%ssignature/%s/%s.sig",DATA_DIR,id[0..0],id);

  if (sig = read_file (sigfn))
    note["msg"] = text + "\n--\n"+sig;
  else
    note["msg"] = text;

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
  tell_object(me,"�d�������C\n");

  // Keep track which post we were reading last time.
//  if ( !mapp(last_read_time) )
//    me->set("board_last_read",([ myid: note["time"] ]) );
//  else if (undefinedp(last_read_time[myid]) || note["time"] >
//    last_read_time[myid] )
// {
//    last_read_time[myid] = note["time"];
//  }

  board->save();
  return;
}

void ed_exit()
{
  object board;
  mapping note;
  string fn,buf;
  string sigfn,sig,myid;

  seteuid(ROOT_UID);
  board = this_player()->query_temp("post/board");
  note = this_player()->query_temp("post/note");
  fn = this_player()->query_temp("post/fn");

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

int main(object me,string arg)
{
  object  board;
  mapping note=([ ]);

  if (me != previous_object()) return 0;

  seteuid(geteuid(me));

  if (!arg) return help(me);

  if (!board = present("board",environment(me)))
    return 0;

  note = allocate_mapping(4);
  note["title"] = "��"+arg;
  note["author"] = me->query("name")+"("+getuid(me)+")";
  note["time"] = time();
  
  me->edit( (: done_post,me,board,note :) );
  return 1;
	
//  write("�z�n�b�s��ɼȰ��Ҧ��T��(�]�A�Q����)��������?(y/n) ");
//  return input_to( (: to_post :), me,arg,board );
}
/*
int to_post(string yn,object me,string arg,object board)
{
  mapping note=([ ]);

  note = allocate_mapping(4);
  note["title"] = "��"+arg;
  note["author"] = me->query("name")+"("+me->query("id")+")";
  note["time"] = time();
  
  if( yn =="y") me->set_temp("halt_msg_in_edit",1);
  else me->set_temp("halt_msg_in_edit",0);
  me->edit( (: done_post,me,board,note :) );
  return 1;

} 
*/
int help(object me)
{
  write(@HELP
���O�榡 : post <���D>

���O���� : �b���d���O���a��i�H�Υ��R�O�ӶK���i�A

	�p: >post ��BUG!!

�������O: followup signature �C
HELP
    );
    return 1;
}