#include <ansi.h>
#include <combat.h>     
inherit NPC;

void heal();
void create()
{
  set_name(CYN"角脊鐵龍"NOR, ({"shell dragon","dragon"}) );
  set("long",@LONG
一隻渾身硬皮長滿尖刺的巨龍，牠的背脊呈角形，超重的身軀使得牠
移動緩慢，當牠的重踏地面時有如天崩地裂，非常可怕。
LONG
);
  set("race", "beast");
  set("gender", "雄性");
  set("unit","隻");
  set("age",1000);
  set("level",43+random(3));
  set("evil",40);
  set("title",RED"  魔獸 "NOR); 
  set("attitude", "aggressive");
  set("limbs", ({ "頭部", "背部","尾巴","前爪","後爪"}) );
  set("verbs", ({ "bite","crash","claw" }) );
  set("con",110);
  set("int",20);
  set("dex",20);
  add("addition_damage",80);
  add("addition_armor",150);
  set("chat_chance", 30);
  set("chat_msg", ({
     (: heal :),
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

void heal()
{
  if(query("hp") > query("max_hp")) return;
  add("hp",70+random(50));
  return;
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(10))
  {
    me->start_busy(2);
    target->add_busy(1);
    message_vision("\n$N"HIW"猛力頓地，造成山搖地動，崩山走石！！\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  else if(!random(10))
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      damage = random(100)+50;
      message_vision(HIR"$N一時身形俱失無法站穩，被一些落石擊中... "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      inv[i]->add_busy(1+random(3));
      COMBAT_D->report_status(inv[i]);
    }
  }
  return;
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
    case  0..59: 
          new(__DIR__"eq/shell-dragon-blood")->move(this_object());
          break;
    case  60..79: 
          new(__DIR__"eq/shell-dragon-blood")->move(this_object());
          new(__DIR__"eq/shell-dragon-blood")->move(this_object());
          break;
    case  80..89: 
          new(__DIR__"eq/shell-dragon-blood")->move(this_object());
          new(__DIR__"eq/shell-dragon-blood")->move(this_object());
          new(__DIR__"eq/shell-dragon-blood")->move(this_object());
          break;
    case  90..99: new(__DIR__"eq/shell-dragon-armor")->move(this_object());
          break;
  }
  ::die();
  return;
}
