#include <weapon.h>
#include <ansi.h>
inherit SWORD; 
inherit F_UNIQUE;
void create()
{
        set_name(HIC"隕天•冰破"NOR, ({ "stone-ice sword" , "sword" }) );
        set_weight(2200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",3); 
                set("value",8000);
                set("unit", "把"); 
                set("long", "採集天外之石所鑄造成的劍，但是全把是藍透明的，中間把柄則是\n"
                            "用冰晶所製，且不融化，但是蠻傷手的。\n"); 
        } 
        set("weapon_prop/con",1);
        set("weapon_prop/dex",2);
        set("weapon_prop/str",-1);
        set("weapon_prop/int",-2);
        set("weapon_prop/bar",-1);
        set("weapon_prop/tec",1);
        init_sword(50+random(3));
        setup();
}


