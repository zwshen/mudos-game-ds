#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
        set_name(HIW"牙曉盔"NOR,({"ya-shou helmet","helmet"}) );
        set("long",@LONG
由象牙製成的頭盔，中間還鑲有一個紫水晶。
LONG
);
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",15);
                set("limit_con",15);
                set("unit", "頂");       
                set("value",1200);          
                set("volume", 3);                       
                set("material", "ivory");   
        }
        set("armor_prop/armor", 7);
        set("armor_prop/str",1);
        setup();
}

