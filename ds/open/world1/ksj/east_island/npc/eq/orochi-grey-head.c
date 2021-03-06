#include <ansi2.h>
inherit NPC;
void normal_ai();

mapping *combat_action = ({
        ([  "action":       "$N高高挺起，以崩山摧石之勢撞向$n",
                "attact_type":  "bar",
                "damage_type":  "內傷",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(GRN"八岐大蛇"RED"．"NOR"灰首"NOR,({"orochi grey head","grey head","head","_GREY_HEAD_"}) );
  set("long",@LONG
八頭八尾，巨大身軀有如八座山峰與八個山谷一般的恐怖大蛇身上長
杉、檜，身長跨八座山頂、山谷，腹部滴著赤血。你現在所看到的部
份是八岐大蛇的八個頭之一，暴食狂噬的灰色蛇首。
LONG
);
  set("race", "野獸");    
  set("unit","隻");
  set("age",2000);
  set("attitude", "aggressive");
  set("level",70);
  set("orochi",1);
  set("orochi_beast_3",1);
  set("limbs", ({ "額鱗","咽喉","眼睛","頭頂"}) ); 
  set("verbs", ({ "bite","crash"}) );     
  set("Merits/bar",13);
  set("Merits/bio",11);
  set("Merits/wit",4);
  set("Merits/tec",7);
  set("Merits/sou",4);
  add("addition_damage",50);
  add("addition_armor",220);
  add("addition_shield",50);
  set_temp("apply/hit",20);
  set("chat_chance", 20);
  set("chat_msg",({
     (: normal_ai() :),
     (: random_move :),
  }) );
  setup();
  carry_object(__DIR__"eq/orochi-armor");
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("_NPC_GREY_HEAD_");
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

int special_attack(object me, object target, int hitchance)
{
  int damage,hp;
  if(!me) return 0;
  if(me->is_busy()) return 0;
  hp=target->query("hp");
  if( !random(8) && (target->query_dex()<100) ) 
  {
    me->start_busy(2);
    target->add_busy(2);
    message_vision("\n$N"HIW"猛然咬住$n的身體，瘋狂地撕咬亂甩！\n"NOR,me,target);
    damage=hp/6;
    if( target->query_dex() < 100) call_out("bite",1,damage,target);
    damage=hp/7;
    if( target->query_dex() < 90) call_out("bite",1,damage,target);
    damage=hp/8;
    if( target->query_dex() < 80) call_out("bite",1,damage,target);
    damage=hp/9;
    if( target->query_dex() < 70) call_out("bite",1,damage,target);
    damage=hp/10;
    if( target->query_dex() < 60) call_out("bite",1,damage,target);
    damage=hp/11;
    if( target->query_dex() < 50) call_out("bite",1,damage,target);
    return 1;
  }
  return 0;
}

void bite(int damage,object target)
{
  message_vision("\n$N"HIR"全身被利牙咬得傷痕纍纍("+damage+")！\n"NOR,target);
  target->receive_damage("hp", damage, this_object());
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
  tell_object(ob,HIG"你得到 10 點聲望。"NOR);
  message("world:world1:vision",
  HIC"\n\t【東方島】："+HIR" 出雲山頂傳來震耳欲聾的慘嚎，"HIY+ob->name(1)
    +HIR"斬下了八岐大蛇的一個首級。\n\n"NOR,users());
  switch( random(100) )
  {
    case  0:
          new(__DIR__"eq/orochi-eye-armor")->move(this_object());
          break;
  }
  ::die();
  return;
}
