#include <ansi.h>
inherit NPC;
void create()
{
       set_name("幼鷹",({"little eagle","eagle"}));
        set("level",4);
        set("race", "野獸");
        set("age", 4);
        set("long", "這是一隻等待媽媽回來的小鷹。\n");
        set("limbs", ({ "頭部", "身體", "腳", "尾巴" }) );
        set("verbs", ({ "bite", "poke" }) );
        setup();
}
