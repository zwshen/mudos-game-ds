#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
        set_name("土司手套", ({ "toast gloves", "gloves" }) );
        set_weight(500);
		set("long", "相當罕見的手套，是土人族群中從不離身的防具，可以加強閃躲能力。");
		set_weight(700);
		if( clonep() )
			set_default_object(__FILE__);
		else 
		{
			set("unit", "對");
			set("volume",2);
			set("value",5000);
			set("material","fur");
		}
 		set("armor_prop/armor", 5);
 		set("armor_prop/dex", 1);
 		set("armor_prop/dodge", 5);
        setup();
}

