#include <npc.h>

void create()
{
    set_name("小蛇", ({ "small snake", "snake" }) );
    set_race("beast");
    set("long", "一隻土褐色的小蛇，舌頭一吐一縮的。\n");
    set("verbs", ({ "bite", "crash"}) );

    set_attr("cor", 2);

    set("age", 1);

    setup();

        advance_stat("gin",30);
        advance_stat("hp",50);
    set_level(2);
    if( random(100) > 95 ) carry_object(__DIR__"obj/gall");
}
