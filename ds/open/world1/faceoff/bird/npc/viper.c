#include <ansi.h>
inherit NPC;
void create()
{
 set_name("蛇",({"viper",}));
 set("long",@LONG
一隻小小的青蛇.
LONG
    );
 set("race","野獸");
 set("attitude", "aggressive");
 set("level",16);
 set("limbs", ({ "頭部", "身體", "尾巴" }) );
 set("verbs", ({ "bite", "claw" }) );
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
}
