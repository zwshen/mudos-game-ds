inherit ITEM;
inherit F_WATER;
void create()
{
	function f;
	set_name("百草藥劑", ({ "herb potion","potion" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
  目前市面上最經濟的藥水。喝(drink) 了可以滋補身體，效果不錯。
LONG);
		set("unit", "瓶");
		set("material","water");
	}
	set("value", 50);    
	set("heal_hp",50);
	set("water_remaining", 1);
	setup();

}
