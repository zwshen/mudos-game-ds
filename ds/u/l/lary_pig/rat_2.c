#include <ansi.h>
inherit NPC;
void create()
{
        set_name("老鼠", ({"rat"}) );
        set("long", "一隻滿身污垢的小動物, 後面還拖著一條長長的尾巴。\n");
        set("unit","隻");
        set("race", "野獸");
        set("limbs", ({ "頭部", "身體", "尾巴", "後腳","前腳"})); //受攻部位
        set("verbs", ({ "bite","claw","crash"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
        set("age", 1);
        set("level",1);
        set("dex",1);
        set("str",1);
        set("con",1);
        set("hp", 1000000000);
        setup();

}

