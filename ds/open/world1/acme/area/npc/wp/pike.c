#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
    set_name(HIG "飛震槍"NOR,({"fei zhen pike","pike"}));
    set("long","這把槍是用精鋼打造而成，是把相當不錯的長槍。\n");
    set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "把");
          set("value",2600);
set("volume",4);
          set("material","iron");
        }
        set("weapon_prop/str",2);
        set("weapon_prop/hit",8);
          init_fork(32);
        setup();
}
