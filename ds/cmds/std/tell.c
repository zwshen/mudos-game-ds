// tell.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);
int ft(object ob);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
        if(!wizardp(me) && me->query("talk_point")<1) return notify_fail("你現在口乾舌燥, 要等一下才有力氣說話喔!\n");
	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(mud, target, me, msg);
		write("網路訊息已送出﹐可能要稍候才能得到回應。\n");
		return 1;
	}

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("沒有這個人....。\n");

    if(obj->query("env/auto_reply") && !wizardp(me) && !ft(obj))
	{
	 if(stringp(obj->query("env/auto_reply"))) 
	 	return notify_fail(HIW+obj->name()+"語音信箱: "+obj->query("env/auto_reply")+"。\n");
	 return notify_fail("對方已設定勿打擾, 聽不到你說的話。\n");
	}
        write("你告訴" + obj->name(1) + "﹕" HIG + msg + "\n" NOR);
        tell_object(obj, sprintf("%s告訴你："HIG"%s\n" NOR,
                me->name(1)+"("+me->query("id")+")", msg));

              /*
	write("你告訴" + obj->name(1) + "﹕" + msg + "\n" NOR);
	tell_object(obj, sprintf( HIW "%s告訴你﹕[1;37;41m【 %s 】[0m\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));
                  */

	obj->set_temp("reply", me->query("id"));
	if(!wizardp(me)) me->add("talk_point",-1);
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)告訴你﹕%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s 告訴你﹕%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int ft(object ob)
{
  string *t_ft;
  t_ft = ob->query("friend");
  if( pointerp(t_ft) && member_array(this_player()->query("id"), t_ft) != -1 )
    return 1;
  return 0;
}

int help(object me)
{
	write(@HELP
指令格式﹕tell <某人> <訊息>

你可以用這個指令和其他地方的使用者說話。

	設定勿打擾: set auto_reply < 1 > 或 < 自動回應文字 >
	解除勿打擾: unset auto_reply 或是 set auto_reply 0
	
其他相關指令﹕reply
HELP
	);
	return 1;
}
