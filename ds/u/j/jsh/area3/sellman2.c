#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("ψ舥ρ馏", ({ "beef noodle-boss", "boss" }) );
        set("long",
                "ψ难舥ρ馏礜ㄓψ难硈癮琳疨常苂ぃ荡\n"
                        ); 
        set("chat_chance",10);
        set("chat_msg",({ 
"ψ难舥ρ馏み羖羖рψちΘ ~ ~\n",
(: command,"sweat" :),
(: command,"say ㄓ， ~ ㄓ， ~ ψ难" :),
}));
        set("sell_list",([
__DIR__"noodle": 5,
]));
        set("level", 20);
        set("no_fight",1);
        set("age", 42);
        set("storeroom", __DIR__"/store2.c");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}

