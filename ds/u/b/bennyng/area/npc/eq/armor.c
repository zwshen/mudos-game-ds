#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIW"守衛鎧甲"NOR, ({ "Saint armor","armor" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這件是聖域守衛所穿的鎧甲，具有很好的防禦力\n");
                set("unit", "件");
                set("material", "steel");
                set("value",5000);
                set("armor_prop/dex",-3);
                set("armor_prop/shield",3);
                set("armor_prop/armor", 20);
                set("armor_prop/dodge",-10);
        }
        setup();
}
