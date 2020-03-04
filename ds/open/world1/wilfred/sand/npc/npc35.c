#include <ansi.h>
inherit NPC;

void create()
{
  set_name(WHT"石神"NOR,({"stone statue","statue"}) );
  set("long",@LONG

一個不甚起眼的石像，好像放在這裡己有相當的時間了，
至於為何沙漠中有這尊石像，便無從得知了，只見這石像
面目威嚴，栩栩如生，宛如活物。

LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",1000);
  set("level",43);
  set("attitude", "heroism");
  set("limbs", ({ "頭部", "腹部","胸部","石拳","石腳","背部" }) );
  set("verbs", ({ "bite","claw" }) );
  add("addition_armor",90);
  add("addition_damage",80);
  setup();
  carry_object(__DIR__"eq/eq3")->wear();
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
HIW+BLK"\n\t【武林消息】"+
NOR+WHT"前古神尊『石神』敗給了"HIW +ob->name(1)+ NOR"。\n\n",users());

   ob->add("popularity",1);
   ::die();
   return;
}
