#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name("碧玉項鍊" ,({ "jade neck","neck" }) );
        set("long","這是一條綠色的項鍊。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(500);
        set("material", "jade");
        set("unit", "個" );
       set("value",1000);
        set("armor_prop/armor", 2);
        set("limit_int",3);
        set("armor_prop/str", 1);
        }
        setup();
}
