#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
set_name("開羅長矛" NOR ,({"kailo-long fork","fork"}));
set("long","開羅士兵所用的長矛，殺傷力不強，但有一定的攻擊程度。\n");
set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",1000);
set("limit_str",20);
set("limit_dex",10);
set("material","wooden");
        }
init_fork(35);
setup();
}

