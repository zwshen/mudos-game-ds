#include <weapon.h>
#include <ansi.h>
inherit FIST;

void create() {
        set_name( "羊角爪" ,({"bariour-horn claw","claw"}));
        set("long",@LONG
這是一個使用羊角做成的爪類武器，質地非常奇特。
LONG
);
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "對");        
                set("value",1000);
                set("volume",2);        
                set("material","ivory");       
        }        
        set("weapon_prop/int", 1);
        init_fist(30);
        setup();
}    

