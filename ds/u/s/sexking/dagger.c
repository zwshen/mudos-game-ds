#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name("小麥草匕首",({"sexking dagger","dagger"}));
        set("long",@LONG
這是一隻用小麥草做成的匕首看起來很軟但很香的樣子。

LONG
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "隻");
                set("material","iron");
                set("no_sac",1);
        }
        set("value",4380);
        set("volume",1);
        set("weapon_prop/bar",1);
        set("weapon_prop/sou",-1);
        set("weapon_prop/dodge",5);
        set("weapon_prop/perception",6);
        set("weapon_prop/hit",11);
        set("backstab_bonus",36);
        init_dagger(10000);
        setup();
}


