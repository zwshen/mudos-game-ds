#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIC"寒鐵頸環"HIR"(S)"NOR,({"ice-iron neck","neck"}) );
        set("long",@LONG
寒鐵鍛製的頸環，外觀製成三龍絞纏的型態，提供頸部相當好的防護。
LONG);
        set_weight(700); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("value",2000);          
                set("volume", 2);                       
                set("material", "steel");

        }
        set("armor_prop/armor",5);       
        setup();
}

int query_autoload() { return 1; }
