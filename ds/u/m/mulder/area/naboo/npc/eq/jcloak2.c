#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
	set_name("武士披風", ({ "jedi cloak","cloak" }) );
	set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是Jedi Knight 的傳統的服飾，看來隱藏了一些神秘力量。\n");
		set("unit", "件");
		set("material", "silk");
		set("no_give",1);
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("value",0);
	}
	set("armor_prop/shield",15);
	set("armor_prop/dodge",5);
	set("armor_prop/armor",20);
	setup();
}
void init()
{
	add_action("cover", "cover");
	add_action("discover","discover");
}
int do_cover(string arg)
{
	object me;
	me->set_temp("apply/id",({"masker"}));
	me->set_temp("apply/name",({"蒙面人"}));
	me->set_temp("apply/short",({"蒙面人(Masker)"}));
	me->set_temp("apply/long",({"一個用黑色披風著全身的神秘人。\n"}));
	message_vision("$N戴上了武士披風。\n",);
}
int do_discover(string arg)
{
	object me;
	me->delete_temp("apply/name");
	me->delete_temp("apply/id");
	me->delete_temp("apply/short");
	me->delete_temp("apply/long");
	message_vision("$N除下武士披風。\n",);
	return 1;
}
int query_autoload() { return 1; }
