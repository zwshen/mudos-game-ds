#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
        set_name("炎虎爪",({"flame claw","claw"}));
        set("long",@LONG
用虎人的利爪製成的武器，鋒利無比。
LONG
);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",10);
        set("unit", "雙");        
        set("value",500);
        set("volume",2);        
        set("material","ivory");       
              }        
        set("weapon_prop/str",1);
        init_fist(40);
        setup();
}    

