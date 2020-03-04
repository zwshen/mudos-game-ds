#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIR"聖炎"HIY"轉龍劍"NOR, ({ "flame turn-dragon sword","sword" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","原來聖炎殿所藏匿的東西，就是這把劍，而這把劍原來一直藏在\n"
                           "轉龍的身體裡，難怪千百年來，無人能找到。\n");
                set("value",30000);
                set("volume",5);
        }
    set("weapon_prop/str",3);
        set("weapon_prop/dex",-2);
    set("weapon_prop/hit",10); 
    set("weapon_prop/bar",1);
    set("weapon_prop/tec",1);
        init_sword(65+this_player()->query("level")/5);
    setup();
}

