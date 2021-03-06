#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("村民", ({ "villager" }) );
    set_race("human");
    set("age", 6);
    set("long", "一個住在哈哈村的村民，似乎無所事事的在街上遊蕩\n");
    setup();
    switch( random(5) ) {
       case 0: carry_object(__DIR__"obj/cloth")->wear(); break;
       case 1: carry_object(__DIR__"obj/armor")->wear(); break;
       case 2: carry_object(__DIR__"obj/belt")->wear(); break;
       case 3: carry_object(__DIR__"obj/boots")->wear(); break;
       case 4: carry_object(__DIR__"obj/gloves")->wear(); break;
    }
    carry_money("coin", 500);
}

int accept_fight(object ob)
{
    do_chat("村民笑哈哈的說道：「哈哈！就憑你也想跟我打？哈！」\n");
    return 1;
}

