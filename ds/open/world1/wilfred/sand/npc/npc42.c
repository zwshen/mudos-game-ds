#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIM"千年龍"NOR,({"thousand dragon","dragon"}) );
  set("long",@LONG
一隻全身長滿了疣的老龍，其體色焦黃，銀白色的龍鬚足有六尺長。
LONG
);
  set("race", "dragon");
  set("unit","隻");
  set("age",1000);
  set("level",45);
  set("attitude", "aggressive");
  set("limbs", ({ "頭部", "腹部","胸部","巨爪","巨尾","背部" }) );
  set("verbs", ({ "bite","claw" }) );
  add("addition_armor",70);
  add("addition_damage",70);

  set("chat_chance", 5 );
  set("chat_msg", ({
(: random_move :),
}) );

  setup();
  set_living_name("dragon_war");
  carry_object(__DIR__"eq/eq21")->wear();
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
   ob->add("popularity",2);
   tell_object(ob,HIC"[你得到額外的 2 點聲望!!]\n"NOR);

   ::die();
   return;
}
