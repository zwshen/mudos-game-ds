#include <weapon.h>
inherit FORK;
void create()
{
    set_name("鋼矛",({"steel spear","spear"}));
    set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "把");
          set("long",@LONG
一把用鋼打造的長矛，矛尖還有放血的溝槽。
LONG);
        }
        init_fork(22);
        setup();
        set("value",1900);
        set("volume", 6);
        set("limit_skill",50);
}
