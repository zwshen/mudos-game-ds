#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(HIR"祕 "HIG"武固"NOR,({ "mi hands","hands" }) );
        set("long","一對神祕的護腕。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",3000);
                set("armor_prop/armor", 4);
        }
        setup();
}

