#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name("斷骨刀", ({ "bone blade","blade" }) );
        set_weight(5500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把可以劈筋斷骨的刀, 是屬於凶殘之人的最愛\n");
                set("material", "iron");
                set("value",4000);
                set("volume",4);
             }
        set("weapon_prop/str",2);
        set("weapon_prop/con",1);
        init_blade(60,TWO_HANDED);
        setup();
}

