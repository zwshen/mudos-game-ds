#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("�s�O", ({ "waiter boss", "boss" }) );
        set("long","�M�����Ӯa�Q�ڦӪA�Ȫ��s�O�C\n");  
        set("chat_chance",10);
        set("sell_list",([
__DIR__"obj/wisgy": 10,  
__DIR__"obj/old-wisgy":10,
]));
        set("level", 1);
        set("no_fight",1);
        set("age", 26);
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}
