inherit ITEM;
inherit F_PILL;
void create()
{
	set_name("內息丹", ({ "breath pill", "pill" }));
	set("long",@LONG
內息丹也是民間所常用的藥丸，主要是用來恢復已失去的體力，跟大
補丸形成相當的對比。
LONG
);
	set_weight(455);
	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
	}
	set("value", 300);
	set("heal",([ "mp":70, ]));
	setup();
}
