// dingtong.c
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("陳達海", ({ "chen dahai", "chen", "dahai" }) );
       set("title", "鏢師");
       set("nickname", "青蟒劍");
       set("gender", "男性" );
       set("age", 43);
       set("level", 35);
       set("long","
一個身穿羊皮襖的高大漢子，虯髯滿腮，說的哈薩克語很不純正，
但目光炯炯，腰間掛著一柄長劍。他是霍元龍手下的鏢師之一。\n" );
       set("attitude", "heroism");

       set_skill("force", 100); 
       set_skill("unarmed", 100);
       set_skill("sword", 100);
       set_skill("dodge", 100);
       set_skill("parry", 100);
//       set_skill("qingmang-sword", 150); 
       setup();
       carry_object(__DIR__"obj/jinjian")->wield();
       add_money("silver", 10);
}

