
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("巧克力球", ({ "chocolate balls","chocolate","balls" }) );
	set_weight(200);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","小巧可愛的巧克力球。\n");
	set("unit", "顆");
	}
        set("heal_mp",18);
	set("value",20);
	set("food_remaining",1);
 setup();
}
