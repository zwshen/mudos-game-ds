#include <ansi.h>
inherit NPC;
void create()
{
       set_name("不知名的動物",({"noname animal","animal"}));
        set("level",15);
        set("race", "野獸");
        set("age", 70);
        set("long", "這是非常大的蟲，牠最喜歡吃骨頭。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾部"}) );
        set("verbs", ({ "bite", "claw"}) );
        setup();
}
