#include <ansi.h>
inherit NPC;
void create()
{
       set_name("小老鼠",({"little rat","rat"}));
        set("level",2);
        set("race", "野獸");
        set("age", 2);
        set("long", "這是一隻被你嚇到的小老鼠。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
