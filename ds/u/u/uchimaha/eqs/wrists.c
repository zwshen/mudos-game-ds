#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(HIC"NIKY護腕"NOR, ({ "niky wrists", "wrists" }) );
        set("long",
                "這是烏漆嗎黑專用的護具。\n");
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "雙" );
                set("armor_prop/armor",  8);
                set("armor_prop/shield",  8);
                set("armor_prop/hit",  100);
                set("armor_prop/dodge",  100);  
                set("limit_dex",4);
                set("value", 1800);
        }
        setup();
}
