#include <ansi.h>
inherit NPC;
void create()
{
        set_name("鴨子" , ({ "duck" }) );
        set("level",2);
        set("dex",-1);
        set("race","野獸");
        set("age",1);
        set("long","他是一隻小鴨子。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}

