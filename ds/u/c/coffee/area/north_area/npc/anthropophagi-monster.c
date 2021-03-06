#include <ansi.h>
inherit NPC;

void create()
{
  set_name(MAG"食"HIW"人獸"NOR, ({"anthropophagi monster","monster"}) );
  set("long",@LONG
一個渾身是血，嘴巴上還叼著一塊肉的怪物，看牠的樣子，好像
要把你吃了似的..
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",45);
  set("gender", "雄性" );
  set("attitude", "aggressive");
  set("level",47+random(4));
  set("title",HIR"魂獸"NOR);
  set("limbs", ({ "獅頭","身體","馬尾","前腳","後腳" }) );
  set("verbs", ({ "bite" }) );
  add("addition_damage",30+random(15));
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(11))
  {
    message_vision(RED"\n$n突然張大嘴，奮力的衝向$N，並且咬了$N的手臂，瞬間！$N的手臂變的血淋淋的。\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(50)+120,me);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(2)+3));
    return 1;
  }
  else if(!random(11))
  {
    message_vision(HIG"\n$n突然狂吼，聲音震的$N簡直塊發瘋了！\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(50)+250-(target->query_shield()),me);
    return 1;
  }
  else if(!random(11))
  {
    message_vision(GRN"\n$n用它的馬尾奮力的甩向$N，結果$N的胸口上出現一道血痕！！"GRN"\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(50),me);
    return 1;
  }
  return 0;
}

int receive_damage(string type,int cost)
{
  object ob,target;
  int i;
  ob = this_object();
  target = this_player();
  ::receive_damage(type,cost,target);
  return 0;
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
  ob->add("popularity",2);
  tell_object(ob,HIG"你得到 2 點聲望。"NOR);      
  ::die();
  return;
}

