#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("比薩多", ({ "bisado boss", "boss" }) );
        set("long","曾留在南洋經商，學會了水果的調酒。\n");  
        set("chat_chance",10);
        set("sell_list",([
__DIR__"obj/grape-wine": 10,  
__DIR__"obj/white-grape-wine.c":10,
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
