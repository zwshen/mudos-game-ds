#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name(HIR"修羅束腰〥"NOR,({"shu lo waist","waist"}) );
        set("long",@LONG
四大塔王之一的燕非彥使用的防具。
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",20);
                set("unit", "條");       
                set("value",3000);          
                set("volume", 3);                       
                set("material", "cold");   
        }
        set("armor_prop/armor",5);       
        set("armor_prop/con",1);
setup();
}

