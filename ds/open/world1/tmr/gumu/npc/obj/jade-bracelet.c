#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
        set_name(CYN"清玉手鐲"NOR,({"jade bracelet","bracelet"}) );
        set("long",@LONG
這是一個看來非常質樸的手鐲，拿在手中的觸感卻帶有點暖意。
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",20);
                set("unit", "個");
                set("light",1);
                  set("value", 6000);
                set("volume", 4);
                set("material", "silk");
        }
        set("limit_con", 30);
        set("armor_prop/armor",5);  
        set("armor_prop/con", 2);
          set("armor_prop/dex", 1);
        setup();
}

