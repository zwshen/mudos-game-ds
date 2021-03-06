// File : "/cmds/wiz/putjail.c"
// Backup : "/cmds/wiz/putjail.bak"
// Rewrote By -Alickyuen@DS- on 2001-11-05

#include <ansi.h>
#define JAIL_ROOM "/open/always/ppl_jail"

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob, where;
	string ppl;
	int i, num;

	if( !str ) return this_object()->help(me);

	if( sscanf(str, "%s because %d", ppl, num)!=2 )
		return this_object()->help(me);

	ob = LOGIN_D->find_body(ppl);

	if( !ob ) return notify_fail("線上並沒有這個人。\n");

        if( userp(me) && wiz_level(ob) >= wiz_level(me)) return notify_fail("你只能抓等級比你低的巫師。\n");

	if( num > 7 || num < 1 )
		return this_object()->help(me);

	message("system","\n\n  [1;35m "+ob->name(1)+"因為違反了遊戲規則而被"+me->name(1)+"抓進了時空監獄接受審判。[0m\n\n",users());
	where=environment(ob);
	tell_room(where,"天空中出現了一個大鐵爪把"+(string)ob->query("name")+"抓了起來, 然後飛走了~~\n", ob);
	tell_object(ob,"一個鐵爪把你抓了起來, 突然你眼前一黑....\n");
	if(where) ob->set("putjail_position",base_name(where));
	ob->set("out_of_power",1); // setting of no power in jail
	ob->move(JAIL_ROOM);
	if( userp(me) ) me->move(JAIL_ROOM);
	tell_object(me, "你把"+(string)ob->query("name")+"抓到了監獄.\n");
	tell_object(ob,".... 醒來時你發現已經被"+(string)me->query("name")+"抓到監獄來了.\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然出現"+"在監獄中\n",({me,ob}));
	ob->save();
	JAIL_ROOM->jail_time(ob, num);
	log_file("putjail",sprintf("[%s] %s go Jail by %s(%s) bcoz %d\n",ctime(time()),ob->name_id(1),me->name(1),getuid(me),num));

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : putjail <某人> because <原因編碼>

此指令可讓你將某人抓到監獄, 你自己也會傳送至監獄方便問話。

原因編碼：
１）Multi	２）Robot	３）Bug		４）Flood
５）Foul	６）Quest	７）Other(1 hour)

＊刑期詳見help guideline＊
HELP
    );
    return 1;
}
