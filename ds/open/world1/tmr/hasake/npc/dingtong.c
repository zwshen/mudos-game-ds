// dingtong.c
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("丁同", ({ "ding tong", "ding", "tong" }) );
       set("title", "鏢師");
       set("nickname", "兩頭蛇");
       set("gender", "男性" );
       set("age", 45);
       set("level", 35);
       set("long","他是霍元龍手下的鏢師之一，一直在這一帶尋找著一個人。\n" );
       set("attitude", "heroism");
       set_skill("force", 140); 
       set_skill("unarmed", 140);
//       set_skill("qingmang-sword", 150);
       set_skill("sword", 140);
       set_skill("dodge", 140);
       set_skill("parry", 140);
       setup();
       carry_object(__DIR__"obj/yinjian")->wield();
       add_money("silver", 1);
}
