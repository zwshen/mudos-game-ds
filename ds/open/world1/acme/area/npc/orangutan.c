#include <ansi.h>
inherit NPC;
void create()
{
        set_name("黑猩猩",({"black orangutan","orangutan" }) );
        set("level",15);
        set("race", "野獸");
       set("age",15);
        set("long", "伳是一隻體形像極了人類的巨大黑猩猩。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
