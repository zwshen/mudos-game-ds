#include <weapon.h>

inherit SWORD;

void create()
{
set_name("塔之長劍",({"tower sword","sword"}));
set("long","這是一把鋒利的寶劍, 劍尖處有個十字型的浮刻。\n");
set_weight(37000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",6100);
set("sword",75);
set("material","gem");
        }
init_sword(860);
setup();
}
