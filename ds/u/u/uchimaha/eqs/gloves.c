#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(HIR"球王"HIC"手套"NOR, ({ "ball gloves", "gloves"  }) );
        set("long",
                "這是烏漆嗎黑專用的護具。\n");
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "雙" );
                set("armor_prop/armor",  10);
                set("armor_prop/shield",  10);
                set("armor_prop/hit",  100);
                set("armor_prop/dodge",  100);  
                set("limit_dex",4);
                set("value", 1800);
        }
        setup();
}


