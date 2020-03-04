#include <ansi.h>
inherit NPC;
void create()
{
 set_name("天梟守衛",({"guard",}));
 set("long",@LONG
你看了一看這一個昔日大教的守衛, 只見他的太陽穴微
微突起, 顯然所修練的內功並不深厚, 但一雙手掌卻粗糙無
比, 想來外家功夫不容小覷.
LONG
     );
 set("attitude","peaceful"); 
 set("age",35);
 set("gender","男性");
 set("level",40);
 set_skill("sky-dagger",30);
 set_skill("dagger",40);
 set("chat_chance",10);
 set("chat_msg", ({"天梟守衛兩眼盯著你看.... .\n",
 }));
 set("chat_chance_combat",20);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
                         (:command,"say 難道天梟人人可欺!!  ":),
 }));
 setup();
 carry_object(__DIR__"eq/owl_cloth")->wear();
 carry_object(__DIR__"eq/dagger")->wield();
 carry_object(__DIR__"eq/owl_armor")->wear();
 carry_object(__DIR__"eq/grass_boots")->wear();
}
