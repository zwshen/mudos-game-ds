#include <ansi.h>
inherit NPC;
void create()
{
 set_name("義民",({"soldier",}));
 set("long",@LONG
一個維護農民安全的義民.
LONG
    );
 set("attitude", "peaceful");
 set("age",40);
 set("gender","男性");
 set("level",20);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/longsword")->wield();
}
