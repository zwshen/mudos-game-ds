#include <ansi.h>
inherit NPC;
void create()
{
       set_name("古代蜻蜓",({"old dragonfly","dragonfly"}));
        set("level",18);
        set("race", "野獸");
        set("age", 500);
        set("long", "這是大蜻蜓。\n");
        set("limbs", ({ "頭部", "身體", "翅膀", "尾巴" }) );
        set("verbs", ({ "bite"}) );
        setup();
}
