#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIC"澤離劍"NOR, ({ "jian lie sword","sword" }) );
        set_weight(19000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",HIC"天下神兵，唯我澤離。\n"NOR);
                set("value",10000);
                set("volume",5);
                set("weapon_prop/con",1);
}

        init_sword(50);
    setup();
}
