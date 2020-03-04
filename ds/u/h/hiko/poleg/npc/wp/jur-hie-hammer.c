#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit HAMMER;

void create()
{
        set_name(HIC"絕海槌" NOR,({"jur hie hammer","jur","hie","hammer"}) );
        set("long",
        "這是一把材質相當不錯的大槌，槌身有著淡藍光芒\n"
        "這把槌聽說是易海在有天看到海中閃現藍光，因此\n"
        "跳入其中尋覓來由時，所發崛到的藍晶所製成，此\n"
        "槌是交由當時旅居泊浪村的打鐵師傅做成，威力十\n"
        "分強大，世上並無幾可比擬。\n"
        );
        set_weight(8000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("value",14000);
                set("limit_str",20);
                set("limit_con",30);
                set("volume",3);
                set("limit_int",10);
                set("limit_dex",5);
                set("limit_skill",70);
        }
   set("weapon_prop/hit",7);
   set("weapon_prop/str",3);
   set("weapon_prop/dodge",7);
   init_hammer(55);
        setup();        
}


