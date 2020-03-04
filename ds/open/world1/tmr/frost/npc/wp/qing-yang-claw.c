#include <weapon.h>
#include <ansi.h>
inherit FIST;

void create() {
        set_name( "青羊爪" ,({"qing-yang claw","claw"}));
        set("long",@LONG
這是一個爪類武器，上頭刻有道教常見的神獸－青羊。青羊爪為莫月柔的隨身武器。
LONG
);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",10);
                set("unit", "雙");        
                set("value",5500);
                set("volume",2);        
                set("material","ivory");       
        }        
        set("weapon_prop/int", 1);
        init_fist(50);
        setup();
}    

