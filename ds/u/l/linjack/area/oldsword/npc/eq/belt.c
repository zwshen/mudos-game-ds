#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
	set_name("腰束", ({ "belt" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是一件很簡單的腰束, 不過通常也要有點身份的人才會用到它.\n");
		set("unit", "條");
		set("material", "cloth");
	}
	set("armor_prop/armor", 1);
	setup();
}
