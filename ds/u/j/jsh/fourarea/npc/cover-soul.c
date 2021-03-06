#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"守護者"HIW"之"HIR"靈"NOR,({"cover soul","soul"}) );
  set("long",
HIC"\n守護者是守著世界之石要塞的大門\n"NOR
HIB"\n以防元素之王闖入人類的世界\n" NOR);
  set("race", "人類");
  set("unit","隻");
  set("age",1240);
  set("level",60);
  set("attitude", "heroism");
  set("limbs", ({ "頭部", "腹部","胸口","腳","手","背" }) );
  set("addition_armor",250);
  set("addition_damage",200);
  set("Merits/bar",5);
  add("apply/hit",60);
  setup();
  carry_object(__DIR__"obj/cover-sword")->wield();
}

void init()
{
  ::init();
  add_action("do_guard","go");
}

int do_guard(string arg)
{
  if(!userp(this_player())) return 0;
  if(arg == "enter")
  {
    message_vision(HIC"$n"HIR"張開雙手將$N擋了下來！\n"NOR,this_player(),this_object());
    write(HIG"要進入世界之石要塞，你必須打倒它\n"NOR);
    if(!random(4))
    {
      message_vision(HIC"$N往$n的方向衝過來，不多說，馬上攻擊/n"NOR,this_object(),this_player());
      kill_ob(this_player());
    }
    return 1;
  }
  return 0;
}

void die()
{
   object ob, env, obj;
   int temp;
   string msg;

   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   } 
   message("world:world1:vision",
   HIC"\n【 守護者 之靈 】  對著"+ob->name(1)+"大喊 : 不要 ~ ~ 不要去啊 ! ! !  。\n\n"+NOR
        ,users());
   ob->add("popularity",1);
   tell_object(ob,HIR"你得到 1 點聲望\n"NOR);


   ::die();
   return;
}

