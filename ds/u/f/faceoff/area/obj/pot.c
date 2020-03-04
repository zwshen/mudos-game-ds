inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("れ表", ({ "pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("no_get",1);
		set("no_sac",1);
                set("long", "竚倒筁┕都ノ\n");
                set("unit", "");
                set("value", 20);
                set("heal_ap",10);
                set("heal_mp",10);
                set("heal_hp",10);
                set("water_remaining",50);
                set("drink_msg","$N舠竬耻碭$n柑\n");
        }
        
        setup();
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
return notify_fail("猔種禟眎: セノ矗ㄑ单き產
都ノ\n");
	}
	else 
	{
		set("heal_ap",40+random(10));
                set("heal_mp",40+random(10));
                set("heal_hp",40+random(10));
		return ::do_drink(arg);
	}
}
