#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name(BLU"惡天"HIR"魔"HIW"披風"NOR,({"Dreamcast cloak","cloak"}) );
        set("long",@LONG
這件披風是從何而來的，沒人知道，相傳是天魔穿的•
LONG
);
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",15);
                set("unit", "頂");       
                set("value",900);          
                set("volume", 3);                       
                set("material", "silk");   
        }
        setup();
}

