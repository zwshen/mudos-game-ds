#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
	set_name("戶政官烏沙帽" ,({ "ossifer's hat","hat" }) );
	set_weight(1300);
	set("long","這是一頂戶政官平時所穿載的帽子。\n");
	if ( clonep() )
		set_default_object(__FILE__);
	else {
        set("material","cloth");
		set("unit", "頂" );
		set("value", 450);
	}
	set("armor_prop/armor", 2);
	setup();
} 
