#include <ansi.h>
inherit ITEM;

mixed *sortinv(object env);

void create()
{
	set_name(HIC"藍天測試儀(解救)"NOR,({"tt5"}));
	set("long","這是一個水藍測試儀。\n");
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","個");
		set("value",9999);
	}
	setup();
}

void init()
{
	add_action("do_tt5","tt5");
}

int do_tt5(string arg)
{
	object me,ob;
	
	me = this_player();

	if(!arg)
		return notify_fail("請指定對象!!\n");

	ob = present(arg, environment(me));
	if (!ob) ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("這裡沒有這個人!!\n");

	if( ob == me )
		return notify_fail("你解救你自己幹嘛阿?\n");

	if( !ob->is_fighting() )
		return notify_fail(ob->query("name")+"目前並沒有跟任何人在戰鬥, 你解救誰阿?\n");

	if( me->is_fighting_ob(ob) )
		return notify_fail("你正在跟"+ob->query("name")+"戰鬥耶...怎麼去解救他阿...\n");
	if( ob->is_fighting_ob(me) )
		return notify_fail(ob->query("name")+"正在跟你戰鬥耶...怎麼去解救他阿...\n");

	if( ! ob->relieve(me) )
		return notify_fail(me->query("name")+"解救"+ob->query("name")+"的行動失敗了...\n");
	else tell_object(me,"解救成功\了﹗\n");

	return 1;
}
