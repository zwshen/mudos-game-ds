//聖誕活動第二名 婷婷(tintin) 禮物 -by tmr-

#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
        set_name(HIR "聖誕紅襪" NOR ,({ "tintin leggings","leggings" }) );
        set("long",
"聖誕活動第二名 婷婷所得獎的禮物。\n"
"一雙大紅色的長泡泡襪，毛絨絨的摸起來非常舒服溫暖。\n"
);
        set_weight(800);

        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "fur");
                set("unit", "雙" );
                  set("value",1000);
                set("valme",1);
                set("no_sac",1);

                  set("armor_prop/armor", 8);
                set("armor_prop/dex",1);
        }
        setup();
}

int query_autoload() { return 1; }
