#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIR"祕 "HIG"嵐衫"NOR,({ "mi cloth","cloth" }) );
        set("long","一件神祕的上衣。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",3000);
                set("armor_prop/armor", 10);
        }
        setup();
}

