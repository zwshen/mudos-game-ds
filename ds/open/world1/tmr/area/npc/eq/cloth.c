#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("布衣",({"cloth"}) );
	set("long","一件用麻布織成的衣服，倒也足夠禦寒蔽體。\n");
	set_weight(200);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","件");
		set("value",50);
		set("volume",2);
		set("armor_prop/armor",1);
	}
	setup();
}
