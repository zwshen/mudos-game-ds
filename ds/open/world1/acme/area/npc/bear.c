#include <ansi.h>
inherit NPC;
void create()
{
        set_name("大灰熊",({"big bear","bear" }) );
        set("level",28);
        set("race", "野獸");
       set("age",15);
        set("long", "牠是一隻具有攻擊性的大灰熊。。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude", "aggressive");
        setup();
}
