#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("小椰", ({ "yeah boss", "boss" }) );
        set("long","這位老闆非常喜歡椰子，連名字都改成有椰字。\n");  
        set("chat_chance",10);
        set("sell_list",([
__DIR__"obj/yeah-wine": 10, 
]));
        set("level", 1);
        set("no_fight",1);
        set("age", 36);
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}


