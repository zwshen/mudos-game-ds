#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("鋼劍",({"steel sword","sword"}) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long",@LONG
這是一把由鋼製成的長劍，看起來閃閃發亮，不難想像它的銳利。
LONG);
        }
        init_sword(19);
        setup();
        set("value",2400);
        set("volume", 6);
        set("limit_skill",30);
}

