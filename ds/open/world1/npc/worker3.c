#include <ansi.h>
inherit NPC;
void create()
{
 set_name("工人",({"worker"}));
 set("long",@LONG
一個勤奮的船廠工人.
LONG
    );
 set("attitude", "peaceful");
 set("evil",-10);
 set("age",21);
 set("gender","男性");
 set("level",6);
 set("chat_chance",10);
set("chat_msg", ({"工人勤奮的在船身上修補. \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"../wp/iron_hammer")->wield();
 carry_object(__DIR__"../eq/worker_cloth")->wear();
}
