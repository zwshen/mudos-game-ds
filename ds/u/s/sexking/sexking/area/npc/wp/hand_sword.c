#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("手�媦C",({"hand sword","hand","sword"}) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("base_volume",1);
                set("base_weight",350);
              set("long",@LONG
這是忍者們戰鬥時慣用的暗器。
LONG);
        }
        init_throwing(20);
        setup();
        set("value",50);
        set("volume", 1);
        set_amount(1);
}
