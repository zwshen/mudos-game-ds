#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name(RED"絕世爛爪"NOR,({"human-claw","claw"}) );
        set("long","一隻世上最爛的武器。\n");
        set_weight(3000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","隻");
        set("value",2500);
        set("material","leather");
        set("weapon_prop/int",2);
                set("volume",2);
        set("weapon_prop/hit",5);
        set("limit_str",30);
        set("limit_level",15);
        set("wield_msg","$N裝備一隻$n"+NOR"當武器，爛爪大喊：『好爛~~好爛~~』。�                                                  M。\n"                                             NOR); 
        }
        set("weapon_prop/int",2);
        set("weapon_prop/hit",5);
        set("beast_weapon_prop/damage",58);
        set("beast_weapon_prop/hit",5);
        set("beast_weapon_prop/int",2);
        init_fist(9999);
        setup();
}


