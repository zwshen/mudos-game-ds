#include <ansi.h>
#include <combat.h>     
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$N揮動手中扇子，將一道寒冷冰氣搧向$n",
                "attact_type":  "wit",
                "damage_type":  "凍傷",
        ]),
        ([  "action":       "$N取出冰製苦無，一連朝$n射出數枚",
                "attact_type":  "bar",
                "damage_type":  "刺傷",
        ]),
        ([  "action":       "$N摧動秘術，將雙手凝成一雙巨大冰爪，左右擊向$n",
                "attact_type":  "bio",
                "damage_type":  "撞傷",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(HIC"青天狗"NOR, ({"blue tengu","tengu"}) );
  set("long",@LONG
能力特強的三色天狗之一，擅於使用冰術，在天狗中的地位僅在黑天
狗之下。
LONG);
  set("race", "人類");
  set("unit","隻");
  set("age",80);
  set("attitude", "aggressive");
  set("gender", "男性" );
  set("level",50);
  set("tengu",1);
  set("title",HIW"三色天狗"NOR); 
  set_skill("unarmed",100);
  set_skill("fork",100);
  set_skill("dodge",100);
  set_skill("parry",100);
  set_temp("apply/hit",30);
  set_temp("apply/dodge",30);
  add("addition_armor",150);
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  set_temp("float",1);
  setup();
  set_living_name("tengu-war-tengu");
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  carry_object(__DIR__"eq/ice-halbert")->wield();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu-enemy") ) this_object()->kill_ob(this_player());
  if(userp(this_player())) this_object()->kill_ob(this_player());
}

int special_attack(object me,object target,int hitchance)
{
  object *inv,z;
  int damage,i;
  inv = all_inventory(environment(me));
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if( !me->query_temp("weapon") && objectp(z=present("ice halbert",me)) )
  { 
    command("wield halbert");
  }

  if( !random(13) )
  {
    me->start_busy(1);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  else if( !random(10) )
  {
    me->start_busy(2);
    message_vision("\n$N"HIW"飛向半空伸展雙翼，使出絕招"HIC"【天狗雹】"HIW"！\n"+NOR,me);
    for(i=0;i<sizeof(inv);i++)
    {
      if(inv[i] == me) continue;
      if( !me->visible(inv[i]) ) continue;
      if( living(inv[i]) && userp(inv[i]) )
      {
        if( inv[i]->is_corpse() ) continue;
        damage = random(100)+370-(inv[i]->query_shield())-(inv[i]->query_armor());
        if(damage < 0) damage=0;
        message_vision(HIR"$N被數不清的尖銳冰雹打中，造成 ("+damage+") 點的嚴重創傷！\n"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage, me);
        inv[i]->add_busy(random(2));
      }
    }
    return 1; 
  }
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
  ob->add("popularity",3);      
  tell_object(ob,HIG"你得到 3 點聲望。"NOR);
  ::die();
  return;
}
