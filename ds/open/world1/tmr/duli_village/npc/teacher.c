#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("教書老師", ({"teacher" }) );
        set_race("human");
        set("age", 60);
        set("long", "一個平凡的老師，在這小漁村以教導村民賺些小錢維生。\n");
        setup();
        set_level(5);
        carry_object(__DIR__"obj/medium-book");
        carry_object("/d/obj/shortsword")->wield();
        
}

int accept_fight(object ob)
{
        return 0;
}


