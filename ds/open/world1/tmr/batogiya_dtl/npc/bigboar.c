#include <npc.h>

void create()
{
    set_name("大野豬", ({ "big wild boar", "boar" }) );
    set_race("beast");
    set("long", "一隻身體相當巨大的野豬，正在用嘴在地上挖來挖去。\n");
    set("verbs", ({ "bite", "crash"}) );

    set_attr("con", 7);

    set("age", 1);

    setup();

        advance_stat("gin", 50);
        advance_stat("hp", 100);
    set_level(5);
}
