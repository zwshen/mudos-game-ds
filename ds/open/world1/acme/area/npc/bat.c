#include <ansi.h>
inherit NPC;
void create()
{
        set_name("蝙輻", ({ "bat" }) );
        set("race", "野獸");
        set("age", 2);
        set("long", "牠是一隻黑色的小蝙蝠。\n");
        set_temp("apply/hit",-20);
        set_temp("apply/dodge",-10);       
        set("level",2);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
