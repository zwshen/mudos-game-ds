#include <weapon.h>
inherit SWORD;

void create()
{
set_name("短劍",({"short sword","sword"}));
set("long","這是一般尋常人所佩帶來防身用的短劍。\n");
set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",800);
set("material","iron");
        }
init_sword(8);
        setup();
}

int query_autoload() { return 1;}
// save eq by alick
