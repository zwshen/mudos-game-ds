#include <ansi2.h>
inherit NPC;
void normal_ai();
void do_combat_attack();

mapping *combat_action = ({
        ([  "action":       "$N張口吐出一道邪魂，快速擊向$n",
                "attact_type":  "sou",
                "damage_type":  "靈體傷害",
        ]),
        ([  "action":       "$N雙眼暴射出一道精光，望向$n的靈魂深處",
                "attact_type":  "sou",
                "damage_type":  "靈體傷害",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(GRN"八岐大蛇"RED"．"HIW"白首"NOR,({"orochi white head","white head","head","_WHITE_HEAD_"}) );
  set("long",@LONG
八頭八尾，巨大身軀有如八座山峰與八個山谷一般的恐怖大蛇身上長
杉、檜，身長跨八座山頂、山谷，腹部滴著赤血。你現在所看到的部
份是八岐大蛇的八個頭之一，駕御邪魂的白色蛇首。
LONG
);
  set("race", "beast");
  set("attack_merits","sou");
  set("unit","隻");
  set("age",2000);
  set("attitude", "aggressive");
  set("evil",200);
  set("level",70);
  set("orochi",1);
  set("orochi_beast_3",1);
  set("limbs", ({ "額鱗","咽喉","眼睛","頭頂"}) ); 
  set("verbs", ({ "bite","crash"}) );     
  set("Merits/bar",8);
  set("Merits/bio",8);
  set("Merits/wit",9);
  set("Merits/tec",4);
  set("Merits/sou",14);
  add("addition_damage",50);
  add("addition_armor",220);
  add("addition_shield",120);
  set_temp("apply/hit",40);
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
  set_living_name("_NPC_WHITE_HEAD_");
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
  message_vision("\n【$N"HIW"的邪力影響，地面上浮現許\多幽魂！】\n"NOR,me);
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
      message_vision("$N"HIW"被靈體侵入身體，造成心靈創傷。"HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      inv[i]->add_busy(random(2));
    }
  }
  return;
}

int special_attack(object me, object target, int hitchance)
{
  int ghost,j;
  ghost=random(5)+4;
  if(!me) return 0;
  if(me->is_busy()) return 0;
  if( me->query_temp("delay") ) return 0;

  if(!random(4)) 
  {
    me->start_busy(2);
    message_vision("\n$N"HIW"從口吐出 "+ghost+" 隻鬼魂！\n"NOR,me);
    for(j=0;j<ghost;j++)
    {
      new(__DIR__"orochi-ghost")->move(environment(me));
    }
    me->set_temp("delay",1);
    call_out("wait",250,me);
    return 1;
  }
  return 0;
}

void wait(object me)
{
  me->delete_temp("delay");
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
    new(__DIR__"obj/obj/white-head")->move(this_object());
new(__DIR__"eq/orochi-waist")->move(this_object());
  tell_object(ob,HIG"你得到 10 點聲望。"NOR);

  message("world:world1:vision",
	HIC"\n\t【東方島】："+HIR" 出雲山頂傳來震耳欲聾的慘嚎，"HIY+ob->name(1)
  	 +HIR"斬下了"+name()+HIR"的首級了。\n\n"NOR,users());
  
  	if(random(1000)==978)
          new(__DIR__"eq/orochi-waist-save")->move(this_object());
  ::die();
  return;
}

