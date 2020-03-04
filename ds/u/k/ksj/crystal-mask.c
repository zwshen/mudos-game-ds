#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
        set_name(HIY"神光晶面"HIR"(S)"NOR,({"crystal mask","mask"}) );
        set("long",@LONG
一個發出光芒的水晶面具，整個面具晶瑩澄澈而且光滑無比，實在是
巧奪天工的作品。
LONG);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_level",25);
                set("unit", "個");       
                set("value",20000);          
                set("volume", 2);                       
                set("material", "stone");   
        }
        set("armor_prop/armor",3);
        set("armor_prop/shield",5);
        setup();
}

int query_autoload() { return 1; }
