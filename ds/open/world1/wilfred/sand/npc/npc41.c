#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIB"翼守龍"NOR,({"wing dragon","dragon"}) );
  set("long",@LONG
此龍身體細長，卻有雙巨大的趐膀，通體淡藍，乍看之下像隻
藍色的大鳥。
LONG
);
  set("race", "dragon");
  set("unit","隻");
  set("age",300);
  set("level",40);
  set("attitude", "aggressive");
  set("limbs", ({ "頭部", "腹部","胸部","巨爪","巨尾","背部" }) );
  set("verbs", ({ "bite","claw" }) );
  add("addition_armor",60);
  add("addition_damage",60);

  set("chat_chance", 5 );
  set("chat_msg", ({
(: random_move :),
}) );

  setup();
  set_living_name("dragon_war");
  carry_object(__DIR__"eq/eq19")->wear();
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

   ob->add_temp("hero",2);
   ob->add("popularity",1);
   tell_object(ob,HIC"[你得到額外的 1 點聲望!!]\n"NOR);

   ::die();
   return;
}
