// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("縉", ({ "dump" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "糛糛荐乃乃縉\n");
		set("unit", "");
		set("value", 15);	//把σ基確翴计羆㎝埃5
		set("heal_hp",20);	//琌"heal_hp"┪琌"heal_mp",常Τ.
		set("food_remaining", 3);
	}
	setup();
}
