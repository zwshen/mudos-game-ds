#include <ansi.h>
inherit NPC;
void create()
{
  set_name("白雲蒼", ({ "by yun zan","by" }) );
  set("gender", "男性" );
  set("long",@LONG
神之四塔之一的守塔天王，原為一浪人劍客，但在一次的行俠仗義中，被月狼子看見，
月狼子便帶白雲蒼去見天界聖神，經一番考驗，取得四塔天王之一的功名。
LONG
);

 set("age",819);
  set("level",41);
  set("title",HIR"四塔天王之一"NOR);
  set("max_hp",33012);
  set("max_mp",1900);
  set("max_ap",2100);
  set("race","human");
  set("chat_chance", 20);
  set_skill("unarmed",91);
  set_skill("sword",100);
  set_skill("parry",80);
  set_skill("dodge",80);
  set("Merits/bar",4);

setup();
  
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

HIR"\n【武林驚傳】"+HIC""+ob->name(1)+"破了神之四塔之一的蒼皇塔。\n\n"NOR,users());
tell_object(ob,HIR"[殺了"HIB"白雲蒼"HIR"的你可得到3點聲望]\n"NOR);

 ob->add("popularity",3);
 ::die();
   return;

}

