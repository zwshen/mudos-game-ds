//updated 26/12
inherit ITEM;
void create()
{
set_name("紅酒", ({ "water bottle","bottle" }) );
set_weight(80);
if( clonep() )
set_default_object(__FILE__);
else {
set("long", "一樽很多年前出產的紅酒。\n");
set("unit", "樽");
set("value", 0); 

}
}
