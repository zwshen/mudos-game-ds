inherit ITEM;
inherit F_WATER;
void create()
{
	set_name("什錦魚湯",({ "fish soup","soup" }) );
	set_weight(500);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
這碗香噴噴的魚湯裡放了好多的新鮮魚肉，讓人忍不住食指大動。
LONG);
	set("unit", "碗");
	set("material","food2");
	}
	set("value",120);
	set("water_remaining",3);
	set("heal_hp",30);
	setup();
}
