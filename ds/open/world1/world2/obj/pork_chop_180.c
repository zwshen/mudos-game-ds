inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("香蒜豬排",({ "garlic pork chop","chop" }) );
	set_weight(800);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
這是一塊由豬身上取下的肉。
LONG);
	set("unit", "塊");
	set("material","food2");
	}
	set("value",180);
	set("food_remaining",5);
	set("heal_hp",40);
	setup();
}
