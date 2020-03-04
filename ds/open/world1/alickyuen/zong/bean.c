#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(MAG"豆沙粽"NOR, ({"bean paste zong"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long", "一隻外面散發著竹葉清香，裡面包著甜甜豆沙的咸肉粽。\n");
		set("unit", "只");
                set("value", 1000);
        }
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();
	if( !arg ) return notify_fail("你要吃什麼?\n");
        if( arg == "bean paste zong" )
	{
		if( me->is_busy() ) return notify_fail("你正在忙中！\n");
		me->set("hp",me->query("max_hp") );
		me->set("mp",me->query("max_mp") );
		me->set("ap",me->query("max_ap") );
                message_vision("$N吃下一個$n。\n", me, this_object() );
		tell_object(me, "你突然覺得全身充滿力氣。\n");
                if(random(10)==0)
		{
			tell_object(me, HIY"你發現粽裡有一張抽獎卷！\n"NOR);
			new(__DIR__"ticket")->move(me);
		} else tell_object(me, HIR"真不好運...這個粽裡沒有抽獎卷...\n"NOR);

        me->start_busy(3);
	call_out( (: destruct(this_object()) :), 1);

	return 1;
	}
}
