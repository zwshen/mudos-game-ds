#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name("鬼頭盾" ,({ "ghost head shield","shield" }) );
        set("long","這是一個有著鬼王頭圖騰的大盾。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
       set_weight(1500);
        set("material", "iron");
        set("unit", "面" );
       set("value",2300);
        set("volume",3);
        }
        set("armor_prop/armor", 15);
        set("armor_prop/con",2);
         set("limit_str",10);
        setup();
}

