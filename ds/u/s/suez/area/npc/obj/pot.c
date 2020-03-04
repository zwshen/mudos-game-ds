inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("大水缸", ({ "pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("no_get",1);
		set("no_sac",1);
                set("long", "一個大水缸，是給大家解渴用的。\n");
                set("unit", "缸");
                set("value", 20);
                set("heal_ap",45+random(6));
                set("heal_mp",45+random(6));
                set("heal_hp",45+random(6));
                  set("water_remaining",70);
        }
}

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me;
	if( !this_object() ) return 0;
	if( !this_object()->id(arg) ) return 0;
	me=this_player();
    if(me->query("level")>5)
	{
return notify_fail("你注意到水缸上貼了張佈告: 本用水只提供等級五級以下的玩家
飲用。\n");
	}
	else return ::do_drink(arg);
}
