// mailbox.c
// ¤W¦¸­×§ï¤é´Á: 1999.10.21 0:51
// ¤W¦¸­×§ïªÌ: Luky
// ­×§ï¤º®e: ­×§ïmailªº½T»{
#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

mapping *mails;

int last_read_time;
int newest_mail_time;
void get_mail_text(mapping mail, string str);

void create()
{
	set_name("«H½c", ({ "mailbox","mail_ob" }) );
	set("long",@LONG

		³o¬O¤@­Ó¥Î¨Ó±H«H¡B¦¬«Hªº«H½c¡M§A¥i¥H¥Î¥H¤U«ü¥O¨Ó³B²z§Aªº¶l¥ó¡R
		
		
		mail <¬Y¤H>               ±H«Hµ¹§O¤H¡C
		replymail <«H¥ó½s¸¹>      ¦^«Hµ¹µo«HªÌ¡C
		forward <«H¥ó½s¸¹> <¬Y¤H> ±N¬Y«Ê«HÂà±Hµ¹§O¤H¡C
		from                      ¬d¬Ý«H½c¤¤ªº«H¥ó¡C
		read <«H¥ó½s¸¹>           ¾\Åª¤@«Ê«H¥ó¡C
		discard <«H¥ó½s¸¹>        ¥á±ó¤@«Ê«H¥ó¡C
LONG
	);
	set("unit", "­Ó");
	set("no_drop", 1);
	set("no_put", 1);
	set("no_insert", 1);
	seteuid(getuid());

}

int set_owner(string id)
{
	set("owner_id", id);
	return restore();
}

void set_last_read(int time)
{
	if(last_read_time < time)
	{
		last_read_time = time;
//		save();
	}
	return ;
}

int query_last_read_time()
{
	return last_read_time;
}
int query_newest_mail_time()
{
	return newest_mail_time;
}

int query_mail_flag()
{
	if(last_read_time < newest_mail_time) return 1;
	else return 0;
}

void init()
{

	if( this_player() && environment()==this_player() )
	{
		set_owner( getuid(this_player()) );
		this_player()->set_temp("mbox_ob", this_object());
		set_name( this_player()->name(1) + "ªº«H½c", ({ "mailbox","mail_ob" }) );
		add_action("do_mail", "mail");
		add_action("do_replymail", "replymail");
		add_action("do_forward", "forward");
		add_action("do_from", "from");
		add_action("do_read", "read");
		add_action("do_discard", "discard");
		if(wiz_level(this_player()) > 4)
		{
			add_action("do_mailall","mailall");
			write(HIW"±z¥i¥H¨Ï¥Î mailall «ü¥O±H«H©Ò¦³ªºª±®a.\n"NOR);
		}
	}
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) ) return 0;

	return DATA_DIR + "mail/" + id[0..0] + "/" + id;
}

void receive_mail(mapping mail)
{
	object ppl;
	if(ppl=find_player(query("owner_id")))
	{
                write("¤w³qª¾ " + ppl->short(1) + " ¦¬«H!\n");
                tell_object(ppl,HIG"\n  Ouch!! §A¬ðµM³Q¤Ñ¤W±¼¤U¨Óªº°s²~¥´¨ìÀY, °s²~¸H¤ù¸Ì¦³±i¯È¼gµÛ:\n"+HIC"\n\t\t\t  [1;5m±z¦³·s«H¡C\n\n"NOR+"§A§Ï©»Å¥¨£"+this_player()->name(1)+"¦b¤@®ÇÅÑ¯º¡C\n");
	}

	if( !pointerp(mails) ) mails = ({ mail });
	else
	{
		mails += ({ mail });
		if(mail["time"] > newest_mail_time) newest_mail_time=mail["time"];
	}
	save();
	if(!environment()) destruct(this_object());
}

void send_mail(string receiver, mapping mail)
{
        object ob;
	if(!wizardp(this_player()) && this_player()->query("talk_point")<10)
	{
		write("§A¨S¦³¨¬°÷ªº»¡¸ÜÂI¼Æ¡C\n");
		return;
	}
	ob = FINGER_D->acquire_login_ob(receiver);
	if( !ob ) {
		write("¨S¦³³o­Óª±®a¡C\n");
		return;
	}
        // Get the mailbox or make a new one if not found.
        if(!wizardp(this_player())) this_player()->add("talk_point",-10);

        MAIL_D->send_mail(receiver,mail);

}
/*
void send_mail(string rcvr, mapping mail)
{
	object ppl, ob, mbx;
	
	if(!wizardp(this_player()) && this_player()->query("talk_point")<4)
	{
		write("§A¨S¦³¨¬°÷ªº»¡¸ÜÂI¼Æ¡C\n");
		return;
	}
	// Acquire the login object of receiver and mark the arrival of newmail.
	ob = FINGER_D->acquire_login_ob(rcvr);
	if( !ob ) {
		write("¨S¦³³o­Óª±®a¡C\n");
		return;
	}
	ob->set("new_mail", 1);
	ob->save();

	// Get the mailbox or make a new one if not found.
	ppl = find_player(rcvr);
	if(ppl)
	{
		mbx = ppl->query_temp("mbox_ob");
	}
	if( !mbx ) {
		mbx = new(MAILBOX_OB);
		mbx->set_owner(rcvr);
	}

	// Receive the mail and destruct the objects if receiver is off-line.
	mbx->receive_mail(mail);
	if(!wizardp(this_player())) this_player()->add("talk_point",-4);
	if(!ppl)
	{
		destruct(ob);
	} else tell_object(ppl,HIG"\n  Ouch!! §A¬ðµM³Q¤Ñ¤W±¼¤U¨Óªº°s²~¥´¨ìÀY, °s²~¸H¤ù¸Ì¦³±i¯È¼gµÛ:\n"+HIC"\n\t\t\t  [1;5m±z¦³·s«H¡C\n\n"NOR+"§A§Ï©»Å¥¨£"+this_player()->name(1)+"¦b¤@®ÇÅÑ¯º¡C\n");
	if(!environment(mbx)) destruct(mbx);
}
*/
int do_mail(string arg)
{
	mapping mail;
         string t1,t2;
	if( this_player()!=environment() ) return 0;

	if( !arg || arg=="" )
		return notify_fail("§A­n±H«Hµ¹½Ö¡S\n");
	if(sscanf(arg, "%s %s", t1, t2) == 2 )	return notify_fail("«ü¥O®æ¦¡: mail <who>\n");
	mail = ([
		"from":	this_player()->name(1) + "(" + getuid(this_player()) + ")",
		"title": "µLÃD",
		"to": arg,
		"time": time(),
		"text": ""
	]);
	write("«H¥ó¼ÐÃD¡R");
	input_to("get_mail_title", mail);
	return 1;
}

int do_mailall(string arg)
{
	mapping mail;
	if( this_player()!=environment() ) return 0;
	mail = ([
		"from":	this_player()->name(1) + "(" + this_player()->query("id") + ")",
		"title": "µLÃD",
		"to": "all players",
		"time": time(),
		"text": ""
	]);
	write("«H¥ó¼ÐÃD¡R");
	input_to("get_mail_title", mail);
	return 1;
}

void get_mail_title(string str, mapping mail)
{
	if( str!="" ) mail["title"] = str;
	write("«H¥ó¤º®e¡R\n");
	this_player()->edit( (: get_mail_text, mail :) );
}

void get_mail_text(mapping mail, string str)
{
	string sigfn,id,sig;
	id=getuid(this_player());
	sigfn = sprintf ("%ssignature/%s/%s.sig",DATA_DIR,id[0..0],id);
	if (sig = read_file (sigfn))
    		str = str + "\n--\n"+sig+NOR;
  	else
    		str = str+NOR;
	mail["text"] = str;
	write("±z¦Û¤v­n¯d¤@¥÷³Æ¥÷¶Ü(y/n)¡S[n]");
	input_to("confirm_copy", mail);
}
void confirm_copy(string yn, mapping mail)
{
	mapping old_mail;
        if( yn[0]=='y' || yn[0]=='Y' )
        {
        	old_mail = ([
		"from":	mail["from"],
		"title": "µLÃD",
		"to": mail["to"],
		"time": mail["time"],
		"text": mail["text"]
		]);
        	old_mail["title"]="[³Æ¥÷] "+mail["title"];
        	receive_mail(old_mail);
        }

        if(mail["to"] == "all players")
        {
        	MAIL_D->send_mail_to_all(mail);
        	write("¨t²Î¥¿¦b±H«Hµ¹©Ò¦³ªºª±®a,³o¥i¯à»Ý­n´X¤ÀÄÁªº®É¶¡.\n");
        	return;
        }
        else send_mail(mail["to"], mail);
        write ("½Ð°ÝÁÙ¦³­n±Hµ¹½Ö¶Ü(y/n) ? [n]");
        input_to ("confirm_other", mail);
}

void confirm_other(string yn, mapping mail)
{
        if ( yn[0]=='y' || yn[0]=='Y' ) {
          write ("½Ð¤@¦¸¤@­Ó¿é¤J¦W³æ, µ²§ô½Ð¥Î¥yÂI '.'  : ");
          input_to("mail_other", mail);
        }
        else write("«H±H¥X¥h¤F¡C\n");
}

void mail_other(string name, mapping mail)
{
        if (name == ".")
          write ("«H±H¥X¥h¤F¡C\n");
        else {
	  mail["to"] = name;
          send_mail(name, mail);
          write ("½Ð¤@¦¸¤@­Ó¿é¤J¦W³æ, µ²§ô½Ð¥Î¥yÂI '.'  : ");
          input_to("mail_other", mail);
        }
}

int do_from()
{
	int i;

	if( !pointerp(mails) || !sizeof(mails) ) {
		write("§Aªº«H½c¤¤¥Ø«e¨S¦³¥ô¦ó«H¥ó¡C\n");
		return 1;
	}
	write("§Aªº«H½c¤¤²{¦b¦@¦³ " + sizeof(mails) + " «Ê«H¥ó¡R\n\n");
	for(i=0; i<sizeof(mails); i++)
	{
		printf("%s\n%2d %-50s ±H«H¤H¡R%-20s"NOR,last_read_time<mails[i]["time"]? HIG : "",
			i+1, mails[i]["title"], mails[i]["from"] );
	}
	write("\n\n");
	return 1;
}

int do_read(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("§A­nÅª­þ¤@«Ê«H¡S\n");

	if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
		return notify_fail("¨S¦³³o­Ó½s¸¹ªº«H¥ó¡C\n");

	num --;

	printf("«H¥ó¼ÐÃD¡R%s\n±H «H ¤H¡R%s\n\n%s\n",
		mails[num]["title"], mails[num]["from"], mails[num]["text"] );
	set_last_read(mails[num]["time"]);
	save();
	return 1;
}

int do_discard(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("§A­n¥á±ó­þ¤@«Ê«H¡S\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("¨S¦³³o­Ó½s¸¹ªº«H¥ó¡C\n");

	num --;
	set_last_read(mails[num]["time"]);
	mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
	save();
	write("Ok.\n");

	return 1;
}

int do_forward(string arg)
{
	string dest;
	int num;
	mapping m;

	if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
		return notify_fail("§A­n±N­þ¤@«Ê«HÂà±Hµ¹§O¤H¡S\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("¨S¦³³o­Ó½s¸¹ªº«H¥ó¡C\n");

	num --;

	m = ([]);
	m["title"] = mails[num]["title"];
	m["text"] = mails[num]["text"];
	m["time"] = mails[num]["time"];
	m["from"] = mails[num]["from"] + "/Âà±H¦Û" + this_player()->query("name");
	m["to"] = dest;
	send_mail( dest, m );
	write("Ok.\n");

	return 1;
}

int do_replymail(string arg)
{
	int num,i;
	object me;
	string t1,t2,text,old_text,temp_text,*tmp,dest,title;
	mapping mail,old_mail;
	me=this_player();

	if( !arg || sscanf(arg, "%d", num)!=1 )	return notify_fail("§A­n¦^ÂÐ­þ¤@«Ê«H¡S\n");

	if( !pointerp(mails) || num > sizeof(mails) ) return notify_fail("¨S¦³³o­Ó½s¸¹ªº«H¥ó¡C\n");
	num--;
	if( this_player()!=environment() ) return 0;
	old_mail=([]);
	old_mail = mails[num];
	t1=old_mail["from"];
	if(sscanf(t1,"%s(%s)", t2,dest)!=2) return notify_fail("µLªk¿ë»{±H¥óªÌ¡C\n");

  // mail ¬O­n½sªº«H¡Anotes ¬OªO­±¤Wªº«H
  // old_mail ¬O­n¦^ªº«Hªº¤º®e¡A¤]´N¬OÂÂ«H¤º®e,
  // temp_mail «h¬O§ï note1 ªº¼È®É«Hªº¤º®e

  title = old_mail["title"];
  title = replace_string(title,"¦^ÂÐ:","");
  title = "¦^ÂÐ:"+title;
  old_text=old_mail["text"];

  old_text = sprintf (" %s        [%s]%sªº¨Ó«H:\n%s\n%s",
                old_mail["title"]+"",
                ctime(old_mail["time"])[4..9]+"",
                old_mail["from"]+"",
                "=============================================================",
                old_mail["text"]+"");
                
  old_text = replace_string(old_text,CYN,"");
  old_text = replace_string(old_text,NOR,"");
  temp_text = CYN+":"+old_text;
  //note1 = replace_string(note2,"\n",CYN+"\n: ");
  temp_text = replace_string(temp_text,"\n","\n"+CYN+": ");
  temp_text = temp_text[0..<3];
  temp_text = temp_text+NOR+"\n";

  tmp = explode(temp_text,"\n");
  text="";
  for(i=0; i < sizeof(tmp); i++)
  {
    if (tmp[i] == CYN+": --") break;  //Ã±¦WÀÉ
    if (strsrch(tmp[i],": : :") != 0) text += tmp[i] + "\n";
  }
  tmp = 0;
  text = text+NOR+"\n";
  
  mail = ([
		"from":	this_player()->name(1) + "(" + this_player()->query("id") + ")",
		"title": title,
		"to": dest,
		"time": time(),
		"text": ""
  ]);
  this_player()->edit( (: get_mail_text, mail :),text );
  return 1;
  
//  write("±z­n¦b½s¿è®É¼È°±©Ò¦³°T®§(¥]¬A³Q§ðÀ»)ªº±µ¦¬¶Ü?(y/n) ");
//  return input_to( (: to_post :), me,board,note,note1 );

}

void owner_is_killed() { destruct(this_object()); }
