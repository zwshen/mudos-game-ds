#include <ansi.h>

inherit NPC;



void create()

{

  set_name(HIC"上校"NOR, ({ "god general","god","general"}) );

  set("gender", "男性" );

  set("long",@LONG

天界中能力算中等的守衛上校﹗

LONG

);



  set("title",HIW"天界"HIR"Ｂ級"NOR);

  set("age",900);

  set("level",29);

  set("race","human");

  set("chat_chance", 20);

  

  setup();

  

  

  carry_object(__DIR__"eq/e5")->wear();

  carry_object(__DIR__"wp/w5")->wield();

}

  

  



  
