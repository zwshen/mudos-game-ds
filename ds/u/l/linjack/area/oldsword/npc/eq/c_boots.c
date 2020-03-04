#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name("行雲鞋", ({ "cloud boots","boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這雙鞋子非常的輕而且結實, 聽說穿了可以行雲流水\n"
                           "般的在空中行走, 而且手工精巧, 不知是那位名家所做.\n");
		set("unit", "雙");
		set("value",8000);
		set("material","cloth");
		set("limit_dex",10);
		set("limit_int",5);
	}
	set("armor_prop/dex",1);
	set("armor_prop/armor",4);
	set("armor_prop/shield",2);
	setup();
}
