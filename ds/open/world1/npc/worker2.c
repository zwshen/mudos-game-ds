#include <ansi.h>
inherit NPC;
void create()
{
 set_name("工頭",({"worker"}));
 set("long",@LONG
他是今年才到任的修船廠工頭, 你看他一身沾滿油汙的工
作服, 就可以知道他是工作勤奮的工頭, 也因為有這種工人
才創造出修船廠的高效率.
LONG
    );
 set("attitude", "peaceful");
 set("evil",-20);
 set("age",34);
 set("gender","男性");
 set("level",19);
 set("chat_chance",10);
set("chat_msg", ({"工頭吆喝著工人作工 \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"../wp/iron_hammer")->wield();
 carry_object(__DIR__"../eq/worker_cloth")->wear();
}
