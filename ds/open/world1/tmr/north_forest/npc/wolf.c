#include <ansi.h>
inherit NPC;
void create()
{
        set_name("黑狼" , ({ "dark wolf","wolf","dark" }) );
        set("level",15);
        set("race","野獸");
        set("gender","男性");
        set("age",35);
        set_skill("parry", 30);
set("verbs", ({ "claw" }));
        set_skill("unarmed", 20);
        set_skill("dodge", 30);
        set("long","一隻兇猛的動物。\n");
        setup();
}


