// 山貓(adx) by snow 2000-05-15

#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "比武台");
	set ("long", @LONG
這里就是比武場的大比武台，一丈來高的比武台上鋪著猩紅色的地毯
比武台兩邊的兵器架上擺放著兩排十八班兵器作為裝飾。比武台后面是一
個貴賓席，只有巫師和小雪初晴的武林宗師可以坐在哪里。
LONG);
	set("info_sends",1);
	set("no_die",1);
	set("exits", ([
		"north"   : __DIR__"caipan",
		"down"   : __DIR__"kantai2",
	]));
	setup();
}

void init()
{
	add_action ("do_fight","fight");
	add_action ("do_fight","kill");
	add_action ("do_fight","hit");
	add_action ("do_work","quit");
	add_action ("do_work","halt");
}

int do_fight(string arg)
{
	object me=this_player();
	object *inv=all_inventory(environment(me));
	object ob;
	object who;
	int i;

	if(!arg) { 
		write("你要同誰比武？\n");
		return 1;
	}
	ob=present(arg, environment(me));
	if(!ob) {
		write("這裡沒有這個人！\n");
		return 1;
	}
	if(ob==me) {
		write("你要和自己比武？？？\n");
		return 1;
	}
	if(!interactive(ob)) {
		write("他現在無法和你比武！\n");
		return 1;
	}
	if(!userp(me) || !userp(ob)) {
		write("他現在無法和你比武！\n");
		return 1;
	}

	for(i=0; i<sizeof(inv); i++) {
		who=inv[i];
		if(who->is_fighting()) {
			write("台上"+who->query("name")+"等正在比武，請稍侯！\n");
			return 1;
		}
	}

	message("channel:chat",HIW"【比武場】"+
		me->query("family/family_name")+"的"+me->query("name")+"與"+
		ob->query("family/family_name")+"的"+ob->query("name")+
		"在比武台上較量高低！\n\n"NOR,users());

	me->set("biwu_fighter",1);
	ob->set("biwu_fighter",1);

	me->kill_ob(ob);
	ob->kill_ob(me);
	return 1;
}

void info_sends(string str)
{
	tell_room(__DIR__"kantai1", str);
	tell_room(__DIR__"kantai2", str);
	tell_room(__DIR__"kantai3", str);
}

int no_die(object me)
{
	object ob = me->query_temp("last_opponent");
	object obj, where;
	string id=ob->query("id");
	string id1=me->query("id");

	me->delete_temp("last_opponent");
	ob->delete_temp("last_opponent");
	me->delete_temp("last_damage_from");
	ob->delete_temp("last_damage_from");
	me->remove_all_killer();
	ob->remove_all_killer();
	me->reincarnate();
	ob->reincarnate();
	message("channel:chat",HIW"【比武場】"+
		ob->query("family/family_name")+"的"+ob->query("name")+"在比武台擊敗"+
		me->query("family/family_name")+"的"+me->query("name")+"！\n\n"NOR,users());

	message_vision(CYN"$N重重地摔在地上！\n"NOR,me);
	message_vision(CYN"\n$N慢慢從地上爬將起來，被壯漢扶著走下比武台。\n"NOR,me);
	me->move(__DIR__"kantai1");
	message_vision(CYN"$N被壯漢扶著慢慢走了過來。\n"NOR,me);
	message_vision(CYN"幾名壯漢歡呼著簇擁著$N走下比武台。\n"NOR,ob);
	ob->move(__DIR__"kantai3");
	message_vision(CYN"$N被几名壯漢簇擁著走了過來。\n"NOR,ob);

	me->delete("biwu_fighter");
	ob->delete("biwu_fighter");

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	obj=present("gongping zi", where);
	if(obj->query("fangshi")!="個人賽") {
		if(obj->query("start/juesai"))
			obj->jieshu_biwu(id, id1);
			obj->keep_biwu(id);
	}
	return 1;
}

int do_work()
{
	write("這裡不能使用這個指令！\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( !wizardp(me) && dir=="north" ) {
		return notify_fail("你不是巫師不能到貴賓席。\n");
	}

	if ( !wizardp(me) && dir=="down" ) {
		if( me->query("biwu_fighter") )
			return notify_fail("你馬上要比武了，不要到處亂跑。\n");
	}

	me->delete_temp("last_opponent");
	me->delete_temp("last_damage_from");
	me->remove_all_killer();

	return ::valid_leave(me, dir);
}

