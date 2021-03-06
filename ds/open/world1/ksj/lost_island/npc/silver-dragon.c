#include <ansi.h>
inherit NPC;
void heal();

void create()
{
  set_name(HIW"銀翼龍"NOR, ({"silver dragon","dragon"}) );
  set("long",@LONG
渾身雪白的飛龍，站立地面時比一間屋子還大，兩翼張開足以遮去半
片天空，習慣以寒冰氣息凍住獵物後再馬上吞食其充滿熱血而滾燙的
心臟。
LONG);
  set("race", "beast");
  set("gender", "雌性");
  set("unit","隻");
  set("age",1100);
  set("level",45);
  set("evil",50);
  set("title",RED"  魔獸 "NOR); 
  set("attitude", "aggressive");
  set("limbs", ({ "頭部", "腹部","胸部","尾巴","前爪","後爪","兩翼" }) );
  set("verbs", ({ "bite","crash","claw" }) );
  add("addition_armor",50);
  set("chat_chance", 40);
  set("chat_msg", ({
     (: heal :),
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

void heal()
{
  if(query("hp") > query("max_hp")) return;
  add("hp",50+random(50));
  return;
}

int special_attack(object me, object target, int hitchance)
{
  int damage;
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(10))
  {
    message_vision(HIW"\n銀翼龍"NOR"突然飛上半空，隨即旋轉俯衝而下，高速從$n身旁旋割而過！\n"NOR, this_object(), target);
    if(random(target->query_dex()) < 30)
    {
      damage=300-( target->query_armor() )+random(150);
      target->receive_damage("hp",damage,me);
      message_vision("造成$N"HIR" "+damage+" "NOR"點的傷害！\n\n",target);
      target->apply_condition("blooding", target->query_condition("blooding")+(random(5)+3));
    }
    else
    {
      message_vision(HIC"$N一個翻滾，驚險地避了開來！\n\n"NOR,target);
      return 1;
    }
    return 1;
  }

  else if(!random(10))
  {
    message_vision(HIW"\n銀翼龍"HIC"朝$N張口噴出急凍寒氣！\n"NOR, target);
    if(random(target->query_dex()) < 30)
    {
      damage=250-( target->query_shield() )+random(100);
        if( damage <  30 ) damage = 30 + random(50);
      target->receive_damage("hp",damage,me);
      message_vision("造成$N"HIR" "+damage+" "NOR"點的凍傷！\n\n",target);
      target->add_busy(1);
    }
    else
    {
      message_vision(HIC"$N一個翻滾，驚險地避了開來！\n\n"NOR,target);
      me->start_busy(1);
      return 1;
    }
    return 1;
  }

  return 0;
}

int receive_damage(string type,int cost)
{
  object ob,target;
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
  switch( random(99) )
  {
    case 0..89: new(__DIR__"eq/silver-dragon-heart")->move(this_object());
         break;
    case 90..99: new(__DIR__"eq/silver-dragon-claw")->move(this_object());
         break;
  }
  ::die();
  return;
}
