#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("女性套裝",({"dress"}) );
        set("long","高雅的套裝，可以襯托出修長的身段以及古典的氣質。\n");
        set_weight(300);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","件");
                set("value",150);
                set("volume",1);
                set("armor_prop/armor",1);
        }
        setup();
}



