#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ÂC³½",({ "tunny" }) );
         set("level",15);
        set("race", "³¥Ã~");
        set("age", 2);
        set("long", "¤@°¦ÂC³½, ÁöµM¦×½è¨S¦³ÂD³½¨Î, ¦ý¾P¸ô¤]¤£®t¡C\n");
        set("limbs", ({ "¯ÝÅ_", "§ÀÅ_", "¸¡Å_", "§À³¡", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
      carry_object(__DIR__"obj/tunny_meat");
}