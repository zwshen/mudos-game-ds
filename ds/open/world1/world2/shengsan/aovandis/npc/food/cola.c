inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("可口可樂", ({ "coca cola","cola" }) );
        set_weight(300);
        if( clonep() )
        	set_default_object(__FILE__);
        else
        {
    		set("long", "這是一罐十分受歡迎的飲料，喝(drink)了可以解渴補充體力。\n");
      		set("unit", "罐");
		set("drink_msg","$N拿起一罐$n，咕嚕咕嚕地喝了幾口。\n");
		set("finish_drink_msg","$N將餘下的$n喝光了。\n");
     	}
     	set("value", 20);
        set("heal_ap",5);
        set("heal_mp",4);
	set("water_remaining", 3);
	setup();
}
