#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
        set_name("高頂帽",({"cap","cap"}) );
        set("long",@LONG
高頂方帽，幽遮蘭城守衛標準制服─中看不重用...
LONG
);
        set_weight(100); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "頂");       
                set("value",50);          
                set("volume", 3);                       
                set("material", "cloth");   
        }
        set("armor_prop/armor", 1);
        setup();
}

