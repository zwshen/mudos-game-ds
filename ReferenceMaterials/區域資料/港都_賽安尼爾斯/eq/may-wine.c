#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("梅酒", ({ "may wine","wine" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","由梅子所釀造的酒，香甜的感覺，讓人想一喝再喝。\n");
                set("unit","杯");
        }
        set("value",80);
        set("heal_mp",20);
        set("water_remaining",3);
        setup();
}

