#include <npc.h>

void create()
{
    set_name("大蛇", ({ "big snake", "snake" }) );
    set_race("beast");
    set("long", "一隻土褐色的大蛇，舌頭一吐一縮的。\n");
    set("verbs", ({ "bite", "crash"}) );

    set_attr("cor", 7);

    set("age", 1);

    setup();

        advance_stat("gin",50);
        advance_stat("hp",100);
    set_level(5);
    if( random(100) > 85 ) carry_object(__DIR__"obj/gall");
}
