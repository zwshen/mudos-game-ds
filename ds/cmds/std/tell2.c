// tell.c

#include <ansi.h>
#include <net/i3.h>

inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
        if(!wizardp(me) && me->query("talk_point")<1) return notify_fail("§A²{¦b¤f°®¦ÞÀê, ­nµ¥¤@¤U¤~¦³¤O®ð»¡¸Ü³á!\n");
	if( sscanf(target, "%s@%s", target, mud)==2 )
	{	
		mud = replace_string(mud,"."," ");
		I3_TELL->send_tell(geteuid(me), me->name(1),mud,target,msg);
		write("I3ºô¸ô°T®§¤w°e¥X¡M¥i¯à­nµy­Ô¤~¯à±o¨ì¦^À³¡C\n");
		return 1;
	}

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("¨S¦³³o­Ó¤H....¡C\n");

	if(obj->query("env/auto_reply") && !wizardp(me))
	{
	 if(stringp(obj->query("env/auto_reply"))) 
	 	return notify_fail(HIW+obj->name()+"»y­µ«H½c: "+obj->query("env/auto_reply")+"¡C\n");
	 return notify_fail("¹ï¤è¤w³]©w¤Å¥´ÂZ, Å¥¤£¨ì§A»¡ªº¸Ü¡C\n");
	}
	write("§A§i¶D" + obj->name(1) + "¡R" + msg + "\n" NOR);
	tell_object(obj, sprintf( HIW "%s§i¶D§A¡R[1;37;41m¡i %s ¡j[0m\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	obj->set_temp("reply", me->query("id"));
	if(!wizardp(me)) me->add("talk_point",-1);
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)§i¶D§A¡R%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s §i¶D§A¡R%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
«ü¥O®æ¦¡¡Rtell <¬Y¤H> <°T®§>

§A¥i¥H¥Î³o­Ó«ü¥O©M¨ä¥L¦a¤èªº¨Ï¥ÎªÌ»¡¸Ü¡C

	³]©w¤Å¥´ÂZ: set auto_reply < 1 > ©Î < ¦Û°Ê¦^À³¤å¦r >
	¸Ñ°£¤Å¥´ÂZ: unset auto_reply ©Î¬O set auto_reply 0
	
¨ä¥L¬ÛÃö«ü¥O¡Rreply
HELP
	);
	return 1;
}
