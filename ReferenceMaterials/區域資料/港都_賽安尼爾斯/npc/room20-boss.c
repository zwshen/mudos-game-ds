#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("����", ({ "bata boss", "boss" }) );
        set("long","�o�����D�`���w���ߡA�s�W�r���令�����r�C\n");  
        set("chat_chance",10);
        set("sell_list",([
__DIR__"obj/may-wine": 10, 
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

