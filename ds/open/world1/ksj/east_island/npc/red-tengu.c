#include <ansi.h>
#include <combat.h>     
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$N張口一吐，一道炙熱火燄燒向$n",
                "attact_type":  "wit",
                "damage_type":  "燒傷",
        ]),
        ([  "action":       "$N揮動右手，莫明其妙$n的$l就被火燄圍繞住了",
                "attact_type":  "wit",
                "damage_type":  "燒傷",
        ]),
        ([  "action":       "$N摧動秘術，雙手燃燒著熊熊烈火，猛然擊向$n",
                "attact_type":  "bio",
                "damage_type":  "內傷",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(HIR"赤天狗"NOR, ({"red tengu","tengu"}) );
  set("long",@LONG
能力特強的三色天狗之一，擅於使用炎術，在天狗中的地位僅在黑天
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
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("tengu-war-tengu");
  carry_object(__DIR__"eq/flame-halbert")->wield();
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
  object z;
  int damage;
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if( !me->query_temp("weapon") && objectp(z=present("flame halbert",me)) )
    command("wield halbert");

  if( !random(12) )
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  else if( !random(11) )
  {
    message_vision("\n$N"HIW"飛向半空伸展雙翼，使出絕招"HIR"【天狗燄】"HIW"！\n"+NOR,me);
    damage = random(100)+300-(target->query_shield());
    if(damage < 0) damage=0;
    message_vision(HIR"$N被漫天火燄包圍，造成 ("+damage+") 點的嚴重灼傷！\n"NOR,target);
    target->receive_damage("hp", damage, me);
    target->add_busy(1);
    me->start_busy(1);
    COMBAT_D->report_status(target);
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
