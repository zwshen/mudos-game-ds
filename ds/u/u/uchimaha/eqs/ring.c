#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"球王"HIC"戒指"NOR, ({ "ball ring", "ring"  }) );
        set("long",
                "這是烏漆嗎黑專用的護具。\n");
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "指" );
                set("armor_prop/armor",  5);
                set("armor_prop/shield",  5);
                set("armor_prop/hit",  100);
                set("armor_prop/dodge",  100);  
                set("limit_dex",4);
                set("value", 1800);
        }
        setup();
}


