#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name("皮腰帶",({"leather waist","waist"}) );
        set("long",@LONG
皮革製的腰帶，經過細心保養後閃閃發亮。
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "條");       
                set("value",20);          
                set("volume", 1);                       
                set("material", "leather");   
        }
        set("armor_prop/armor",2);       
        setup();
}

