#include <ansi.h>
inherit NPC;
void create()
{
       set_name("大老鼠",({"rat","rat"}));
        set("level",8);
        set("race", "野獸");
        set("age", 8);
        set("long", "這是一隻巨大的老鼠, 你可以從他火紅的眼神看出\n"
                    "他的饑餓, 以及他獵食你的渴忘, 平常只有一隻時\n"
                    "他們並不足以為懼, 但今天...不會吧...\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("attitude", "aggressive");
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
