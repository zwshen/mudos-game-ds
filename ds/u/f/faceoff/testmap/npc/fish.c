#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"絬辰"NOR,({ "gold line fish","fish" }) );
         set("level",10);
        set("race", "偿脋");
        set("age", 1);
        set("long", "硂琌办程盽ǎ辰摸, ウψ基琌程稧基\n");
        set("limbs", ({ "臺", "Ю臺", "浮臺", "Ю场", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
      carry_object(__DIR__"obj/fish_meat");
}