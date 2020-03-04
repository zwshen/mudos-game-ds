#include <ansi.h>

inherit NPC;



void create()

{

  set_name(HIB"月狼子"NOR, ({ "moon wolf","wolf" }) );

  set("gender", "男性" );

  set("long",@LONG

天界第一猛將，左拿"冰天盾"，右持"月狼斬妖劍"，好不威風。

LONG

);





  set("age",1020);

  set("level",41);

  set("title",HIW"天界"HIR"猛將"NOR);

  set("race","human");

  set("chat_chance", 20);

  set_skill("unarmed",91);

  set_skill("parry",80);

  set_skill("dodge",80);

  set("Merits/bar",4);

  

  setup();

  carry_object(__DIR__"eq/e1")->wear();

  carry_object(__DIR__"wp/w1")->wield();



}

void die()

{

   object ob;

   if( !ob = query_temp("last_damage_from") )

   ob = this_player(1);

   if( !ob )

   {

     ::die();

     return;

   }

 message("world:world1:vision",

HIM"\n【天界怒吼】"HIW"天界"HIR"猛將"HIB"月狼子"HIY"被"+ob->name(1)+"殺死了。\n\n"NOR,users());









   tell_object(ob,HIR"[殺了"HIB"月狼子"HIR"的你可得到3點聲望]\n"NOR);

   ob->add("popularity",3);

   ::die();

   return;

}





  



  





  









  

  
