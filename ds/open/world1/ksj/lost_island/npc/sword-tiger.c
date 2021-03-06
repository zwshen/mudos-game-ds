#include <ansi.h>
#include <path.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(HIW"劍牙"HIY"巨虎"NOR, ({"sword tiger","tiger","_SWORD_TIGER_"}) );
  set("long",@LONG
上古魔獸，兩枝長逾五尺的尖牙露在大嘴之外，加上比屋子還大的身
軀，讓看見的人或動物心中只有死亡的念頭，牠就是稱霸上古的群獸
之王。
LONG
);
  set("gender", "雄性");  
  set("race", "beast");
  set("unit","隻");
  set("age",2500);
  set("level",56);
  set("attitude", "aggressive");
  set("evil",80);
  set("title",RED"  魔獸 "NOR); 
  set("limbs", ({ "頭部", "身體","尾巴","前腳","後腳"}) );
  set("verbs", ({ "bite","crash","claw" }) );
  set("Merits/bar",9);
  set("Merits/bio",7);
  set("Merits/wit",3);
  set("Merits/tec",7);
  add("addition_armor",170);
  add("addition_damage",110);
  set_temp("apply/hit",40);
  set_temp("apply/dodge",30);
  set("chat_chance", 35);
  set("chat_msg", ({
     (: heal :),
     }));
  setup();
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper1");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper2");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper3");

  set_living_name("_NPC_SWORD_TIGER_");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
  if(!random(3))
  {
    message_vision(HIW"劍牙"HIY"巨虎"HIR"對著$N狂吼一聲，$N頓時雙腳發軟！！\n\n"NOR,this_player() );
    this_player()->add_busy(random(2)+1);
  }
}

void heal()
{
  if( query("hp")+500 < query("max_hp") )
  {
    message_vision("$N舔了舔身上的傷口。\n",this_object());
    add("hp",200+random(200));
    return;
  }
  return;
}

int special_attack(object me, object target, int hitchance)
{
        int damage;
  if(!me) return 0;
  if(me->is_busy()) return 0;

// 3.29 新增將人打飛 by ksj
  if(!random(8))
  {
    target->add_busy(3);
    message_vision("\n$N"HIR"朝$n猛力一撞，只見$n如斷線風箏般飛了出去！\n"NOR,me,target);
    damage = 300 - random(target->query_armor());
    if( damage < 1 ) damage = 1;
    target->receive_damage("hp", damage, me);
    target->move(__DIR__"../room20.c");
    tell_room(environment(target),target->query("name")+"從洞中飛了出來，癱倒在地上。\n",target);
    return 1;
  }

  if(!random(7))
  {
    me->start_busy(2);
    target->add_busy(1);
    message_vision("\n$N"HIR"殺紅了雙眼，發出一陣狂吼！！\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
// 3.29 新增奮力一擊 by ksj
  else if(!random(4))
  {
    message_vision( "$N的雙眼露出兇光。\n", me );
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

  message_vision("\n$N"HIR"發狂似地揮動雙爪及利牙，往四周瘋狂攻擊！！\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( inv[i]->query_temp("invis")>2 ) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
       damage = random(100)+400-( inv[i]->query_armor());
      if( damage <1 ) damage = 1;
      message_vision(HIR"$N慘遭利爪擊中，往旁邊飛了出去.... "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
  }
  me->start_busy(2);
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
  message("world:world1:vision",
    HIG"\n\t【遺世島】："+RED"上古魔獸  "HIW"劍牙"HIY"巨虎"HIW"  被英勇的"+ob->name(1)+"消滅了...\n\n"+NOR
    ,users());
  ob->add("popularity",6);      
  tell_object(ob,HIG"你得到 6 點聲望。"NOR);
/* 
  // no more save eq by tmr 2008/03/06
  switch( random(5000) )
  {
    case  0: eqp=new(__DIR__"eq/tiger-sword");
          break;
    case  1: eqp=new(__DIR__"eq/tiger-blade");
          break;
    case  2: eqp=new(__DIR__"eq/tiger-dagger");
          break;
    case  3: eqp=new(__DIR__"eq/tiger-claw");
          break;
    case  4: eqp=new(__DIR__"eq/tiger-whip");
          break;
    case  5: eqp=new(__DIR__"eq/tiger-staff");
          break;
    default:
        eqp=new(__DIR__"eq/huge-tiger-cloth");
          break;
  }
  eqp->move(this_object());
        */
        new(__DIR__"eq/huge-tiger-cloth")->move(this_object());
  ::die();
  return;
}


