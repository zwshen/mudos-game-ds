#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name("菩提項鍊",({"bu-tie neck","neck"}) );
        set("long",@LONG
由一百零八顆黑色珠子所串成的項鍊，具有平靜人心的功用。
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "條");       
                set("value",200);          
                set("volume", 3);                       
                set("material", "wood");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/con",2);
        setup();
}


