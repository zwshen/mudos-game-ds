#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("�GŽ�i", ({ "chung boss", "boss" }) );
        set("long","���x�h�𪺦ѧL�C\n");  
        set("chat_chance",10);
        set("sell_list",([
__DIR__"obj/beer": 10,  
__DIR__"obj/kee-wine":10,
]));
        set("level", 1);
        set("no_fight",1);
        set("age", 66);
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}
