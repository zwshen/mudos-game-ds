#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("���Ħh", ({ "bisado boss", "boss" }) );
        set("long","���d�b�n�v�g�ӡA�Ƿ|�F���G���հs�C\n");  
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
