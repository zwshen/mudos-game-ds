#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "綠鵲" , ({ "cissa" }) );
        set("level",12);
        set("race","野獸");
        set("age",1);
        set("dex",25);
        set("long","這是一種十分難見的鳥類。\n");
        set("limbs", ({ "頭部", "身體", "尾巴" }) );
        set("verbs", ({ "bite", "poke" }) );
        setup();
}


