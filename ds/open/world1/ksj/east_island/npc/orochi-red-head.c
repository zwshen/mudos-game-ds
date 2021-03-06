#include <ansi.h>
inherit NPC;
void normal_ai();
void do_combat_attack();

mapping *combat_action = ({
        ([  "action":       "$N燃燒烈燄如隕石般撞向$n！",
                "attact_type":  "wit",
                "damage_type":  "燒擊傷",
        ]),
        ([  "action":       "$N磨擦利牙引燃從口中呼出的沼氣，形成兩丈長的火柱燒向$n！",
                "attact_type":  "wit",
                "damage_type":  "燒傷",
        ]),
        ([  "action":       "$N張口吐出一粒大火球燒向$n！",
                "attact_type":  "wit",
                "damage_type":  "燒傷",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(GRN"八岐大蛇"RED"．"HIR"赤首"NOR,({"orochi red head","red head","head","_RED_HEAD_"}) );
  set("long",@LONG
八頭八尾，巨大身軀有如八座山峰與八個山谷一般的恐怖大蛇身上長
杉、檜，身長跨八座山頂、山谷，腹部滴著赤血。你現在所看到的部
份是八岐大蛇的八個頭之一，口吐烈燄的紅色蛇首。
LONG
);
  set("race", "beast");    
  set("attack_merits","wit");
  set("unit","隻");
  set("age",2000);
  set("attitude", "aggressive");
  set("evil",200);
  set("level",70);
  set("orochi",1);
  set("orochi_beast_3",1);
  set("limbs", ({ "額鱗","咽喉","眼睛","頭頂"}) ); 
  set("verbs", ({ "bite","crash"}) );     
  set("Merits/bar",11);
  set("Merits/bio",11);
  set("Merits/wit",10);
  set("Merits/tec",3);
  set("Merits/sou",3);
  set_temp("apply/hit",40);
  add("addition_damage",100);
  add("addition_armor",200);
  set("chat_chance", 30);
  set("chat_msg",({
     (: normal_ai() :),
     (: random_move :),
  }) );
  set("chat_chance_combat",40);
  set("chat_msg_combat", ({
     (:do_combat_attack():),
     }) );
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("_NPC_RED_HEAD_");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if( this_player()->query_temp("invis")>2 ) return;
  if(userp(this_player()) ) this_object()->kill_ob(this_player());
  if( this_player()->query("orochi-enemy") ) this_object()->kill_ob(this_player());
}

void normal_ai()
{
  object me,target;
  me = this_object();
  target = this_player();

  if(me->is_busy()) return;
  if( me->query("hp") + 1000 < me->query("max_hp") )
  {
    message_vision("\n$N"HIG"兩眼微閉，靠在岩壁旁休息！\n\n"NOR,me);
    me->receive_heal("hp",1000);
    me->start_busy(1);
  }

  switch( random(30) )
  {
    case  0: message_vision("$N一雙巨大的蛇眼直盯著你瞧．．．\n",me);
          break;
    case  1: message_vision("$N吐出一道如雷響的氣息。\n",me);
          break;
    case  2: message_vision("$N一雙巨大的眼睛掃視四周，尋找獵物。\n",me);
          break;
  }
  return;
}

void do_combat_attack()
{
  object *inv,me;
  int i,damage;
  me=this_object();
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;
  message_vision("\n【$N"HIR"身上綻射出熊熊火舌！】\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( inv[i]->is_corpse() ) continue;
    if( inv[i]->query("orochi") ) continue;
    if( inv[i]->query_temp("invis")>2 ) continue;
    if( living(inv[i]) && userp(inv[i]) )
    {
      damage=200+random(100)-inv[i]->query_shield();
      damage=damage/3;
      if(damage < 0)  continue;
      message_vision("$N"HIR"難以躲避，被烈火所灼傷。"HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
    }
  }
  return;
}

int special_attack(object me, object target, int hitchance)
{
  int fire,j;
  fire=random(4)+2;
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(5)) 
  {
    me->start_busy(2);
    message_vision("\n$N"HIR"突然攻勢一緩，從口吐出 "+fire+" 團八岐烈燄！\n"NOR,me);
    for(j=0;j<fire;j++)
    {
      new(__DIR__"orochi-fire")->move(environment(me));
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
  ob->add("popularity",10);      
    new(__DIR__"obj/obj/red-head")->move(this_object());
new(__DIR__"eq/orochi-gloves")->move(this_object());
  tell_object(ob,HIG"你得到 10 點聲望。"NOR);

  message("world:world1:vision",
  	HIC"\n\t【東方島】："+HIR" 出雲山頂傳來震耳欲聾的慘嚎，"HIY+ob->name(1)
  	 +HIR"斬下了"+name()+HIR"的首級了。\n\n"NOR,users());
  
  
  	if(random(1000)==978)
          new(__DIR__"eq/orochi-gloves-save")->move(this_object());
  ::die();
  return;
}

