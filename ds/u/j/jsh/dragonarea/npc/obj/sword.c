#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIW"長劍"NOR, ({ "long sword", "sword" }));
        set("long", "一把長型的劍。\n");
        set_weight(8000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("volume",3);
                set("material", "crimsonsteel");
                set("limit_skill",20);
                set("limit_str",20);
                      set("value",1200);
                set("limit_lv", 5);
               }
        set("weapon_prop/armor", 8); 
        set("weapon/prop/dodge",-2);       
        set("wield_msg","$N把$n拿在手上。\n");
        set("unwield_msg", "$N把$n放下。\n");

        init_sword(30);
        setup();
}

