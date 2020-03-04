// shoe.c

inherit EQUIP;

void create()
{
	set_name("¤C¬PÂ½¶³¹u", ({ "cloudy shoes", "shoes" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Âù");
		set("value", 6000);
		set("material", "cloth");
		set("armor_type", "feet");
		set("armor_prop/armor", 2);
		set("armor_prop/dodge", 4);
	}
}
