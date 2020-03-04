// dumpling.c

inherit ITEM;
inherit F_WATER;

void create()
{
	set_name("班皊", ({ "beer" }) );
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "瞺炊硄班皊\n");
		set("unit", "瞺");
		set("value", 16);	//把σ基確翴计羆㎝埃5
		set("heal_mp",20);	//琌"heal_hp"┪琌"heal_mp",常Τ.
		set("water_remaining", 3);
	}
	setup();
}
