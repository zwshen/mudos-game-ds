#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
set_name("石斧",({"stone axe","axe"}));
set_weight(56500);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","看起來只有大力士能揮舞這把沉重又結實的大石斧。\n");
            set("unit", "把");
            set("rigidity",96); //硬度
            set("material","stone"); //材質
set("axe",78);
set("weapon_prop/dex",-1);
set("weapon_prop/mus",3);
set("value",6850);
           }
        setup();
}



