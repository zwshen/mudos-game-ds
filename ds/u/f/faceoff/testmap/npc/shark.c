#include <ansi.h>
inherit NPC;
void create()
{
        set_name("鯊魚",({ "shark" }) );
         set("level",24);
       set("attitude", "aggressive");
        set("race", "野獸");
        set("age", 3);
        set("long", "這是近海最兇猛的魚類, 通常遇到都是凶多吉少。\n");
        set("limbs", ({ "胸鰭", "尾鰭", "腹鰭", "尾部", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
      carry_object(__DIR__"obj/shark_bone");
}