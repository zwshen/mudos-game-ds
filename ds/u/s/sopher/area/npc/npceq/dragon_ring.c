#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"龍神戒指"NOR ,({ "dragon ring","ring" }) );
        set("long","一只泛著紅光的魔力戒指。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(50);
        set("material", "shield");
        set("unit", "只" );
        set("value",1000);
set("armor_prop/dex", 1);
        }
        setup();
} 
