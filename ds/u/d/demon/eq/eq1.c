#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name(RED"µ´¥@Äê¤ö"NOR,({"human-claw","claw"}) );
        set("long","¤@°¦¥@¤W³ÌÄêªºªZ¾¹¡C\n");
        set_weight(3000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","°¦");
        set("value",2500);
        set("material","leather");
        set("weapon_prop/int",2);
                set("volume",2);
        set("weapon_prop/hit",5);
        set("limit_str",30);
        set("limit_level",15);
        set("wield_msg","$N¸Ë³Æ¤@°¦$n"+NOR"·íªZ¾¹¡AÄê¤ö¤j³Û¡G¡y¦nÄê~~¦nÄê~~¡z¡Cµ                                                  M¡C\n"                                             NOR); 
        }
        set("weapon_prop/int",2);
        set("weapon_prop/hit",5);
        set("beast_weapon_prop/damage",58);
        set("beast_weapon_prop/hit",5);
        set("beast_weapon_prop/int",2);
        init_fist(9999);
        setup();
}


