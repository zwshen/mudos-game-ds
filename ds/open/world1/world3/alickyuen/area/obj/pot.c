inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("自助飲水機", ({ "drinking machine","machine"}));
        //set_weight(9900); // 9.9公斤.. 似乎不夠
        set_weight(13000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("no_get",1);
		set("no_sac",1);
                set("long", "一部飲水機，置放在地上，給過往的人飲用。\n");
                set("unit", "部");
                set("value", 20);
        }
        //以下由luky修正.
        set("heal_ap",40);
        set("heal_mp",40);
        set("heal_hp",40);
        set("water_remaining",60);
	set("drink_msg","$N從飲水機倒了一杯水，咕嚕咕嚕地喝了幾口。\n");
	set("finish_drink_msg","$N將餘下的水喝光了。\n");
	setup(); //一定要加setup().
}

void init()
{
	//放在這邊才會每次變化
	set("heal_ap",45+random(6));
        set("heal_mp",45+random(6));
        set("heal_hp",45+random(6));
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me;
	if( !this_object() ) return 0;
	if( !this_object()->id(arg) ) return 0;
	me=this_player();
    if( me->query("level") > 5 ) 
      return notify_fail("飲水機上貼了張告示: 本飲水機只提供等級五級以下的玩家飲用。\n");
    else return ::do_drink(arg);
}

