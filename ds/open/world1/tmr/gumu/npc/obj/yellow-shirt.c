#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("黃衫", ({ "yellow shirt", "shirt" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一件黃色絲稠的衣衫，織工精巧，應是出自女子之手。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

