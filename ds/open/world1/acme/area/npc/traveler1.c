#include <ansi.h>
inherit NPC;
void create()
{
        set_name("旅人" ,({ "traveler" }) );
        set("level",4);
        set("race","人類");
        set("gender","男性");
        set("age", 35);
        set("long", "他是一個遊遍世界各地的旅人。\n");
        set("evil",-10);
        setup();
        carry_object(__DIR__"wp/sword.c")->wield();
         add_money("coin",100);
} 

