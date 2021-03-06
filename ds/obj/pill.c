#include <ansi.h>

inherit ITEM;
inherit F_PILL;

int create()
{
        set_name("長生不老丹", ({ "immortality's pill","pill" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("base_unit", "顆");
                set("base_value", 100);
                set("base_weight", 100);
                set("food_stuff", 10);
                set("long", "傳說中的長生不老丹，吃(eating)了不知會有什麼作用。\n");
        }
        setup();
}

void init()
{
	add_action("do_eat","eat");
}

int do_eat(string arg)
{
	object me=this_player();
	if( arg != "immortality's pill" && arg!="pill" )
		return 0;
//	me->supplement_stat("kee", 100);	// At 恢復氣
	me->receive_heal("hp",100);		// Ds 恢復HP

	message_vision("$N吃下了一顆$n。\n",me,this_object());
	if( this_object()->query("fly_speed") )
	{
		message_vision(HIW"$N竟飄了起來，隨即迅速的飛上天空！\n"NOR,me);
		me->set_temp("fly_speed",this_object()->query("fly_speed"));
                me->set_temp("fly_long",120000);
                if( me->query_temp("fly_time") ) me->delete_temp("fly_time");
		me->move(__DIR__"sky.c");
	}

        destruct(this_object());
	return 1;
}
