#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name("蛇皮手套" ,({ "snake gloves","gloves" }) );
        set("long","這是一個用千年巨蟒的皮所縫製成的手套。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(800);
        set("material", "skin");
        set("unit", "個" );
       set("value",1000);
               set("armor_prop/armor", 3);
        set("limit_dex",6);
        set("armor_prop/str", 2);
        set("armor_prop/con", -1);
        }
        setup();
}
