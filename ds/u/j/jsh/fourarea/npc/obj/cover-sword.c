#include <ansi.h>
#include <weapon.h>
inherit SWORD; 
inherit F_UNIQUE;
void create()
{
        set_name(HIC"守護者"HIW"之"HIR"劍"NOR, ({ "cover-sword", "sword" }));
        set("long", "守護者之靈的配劍，對元素之王有特別的效果。\n");
        set_weight(8000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("volume",5);
                set("material", "crimsonsteel");
                set("limit_skill",90);
                set("limit_str",30);
                      set("value",12000);
                set("limit_lv",40);
               }
        set("weapon_prop/armor",20); 
        set("weapon/prop/dodge",10);       
        set("wield_msg",HIC"當$N抽出$n的那一剎那，一環環的強大靈氣正充滿著$n四周。\n");

        init_sword(70);
        setup();
}

