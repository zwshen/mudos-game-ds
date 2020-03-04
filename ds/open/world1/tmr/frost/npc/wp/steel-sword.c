#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
        set_name("¥Õ¿ûªø¼C",({"steel sword","sword"}));
        set("long",@LONG
LONG
);
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "§â");        
        set("value", 1000);
        set("volume",2);        
        set("material","steel");       
        }        
        init_sword(30);
        setup();
}    

