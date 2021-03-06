#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(BLK"黑草"NOR, ({ "black grass", "grass" }) );
	set("long", "黑色的草，不知有甚麼作用。\n");
        set_weight(500);
	set("value", 10);
	set("unit", "棵");
	setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if( arg == "black grass" || arg == "grass" ) 
	{
		message_vision("$N吃下一棵"+this_object()->query("name")+"。\n"NOR, me);
                me->apply_condition("scolopendra_poison", me->query_condition("scolopendra_poison")-random(10));
		if( me->query_condition("scolopendra_poison") < 0 ) me->apply_condition("scolopendra_poison", 0);
		tell_object(me, YEL"你感到體內的蜈蚣毒有所減緩。\n"NOR);
	}
	destruct(this_object());
	return 1;
}
