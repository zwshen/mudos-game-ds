#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
set_name( HIW "【殺  禪】" NOR,({"Sa-Taz sword","sword"}));
set("long","道家代代相傳的絕代好劍。\n");
set_weight(3500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",8000);
set("material","iron");
        }
init_sword(100);
set("weapon_prop/dex",70);
set("weapon_prop/str",70);
set("weapon_prop/con",70);
set("weapon_prop/hit",70);
set("weapon_prop/parry",70);
set("weapon_prop/dodge",70);
set("weapon_prop/damage", 170);
        setup();
}
