#include <armor.h>
inherit ARMOR;
void create()
{
	set_name("綠彩盔甲",({"green armor","armor"}));
	set_weight(5500);            
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
	set("material","leather");
		set("long", "這是一件常常見到的盔甲。\n");
		set("value",  200);
		set("volume",4);
		set("armor_prop/armor",  2);  
	}
	setup();
}
int query_autoload() { return 1;}
// save eq by alick
