#include <ansi.h>
inherit NPC;
void create()
{
       set_name("樹蛙",({"treeer frog","frog"}));
        set("level",10);
        set("race", "野獸");
        set("age", 23);
        set("long", "這是一隻青色的小蛙。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳"}) );
        set("verbs", ({ "bite"}) );
        setup();
}
