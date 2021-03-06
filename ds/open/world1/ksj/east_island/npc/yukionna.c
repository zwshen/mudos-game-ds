#include <ansi.h>
inherit NPC;
varargs int receive_damage(string type, int damage, object who);

mapping *combat_action = ({
        ([  "action":       "$N輕輕吹出一口寒氣，不知不覺間$n的$l漸漸覆著一層冰霜",
                "attact_type":  "wit",
                "damage_type":  "凍傷",
        ]),
        ([  "action":       "$N兩手指地，$n所在的地面上急速長出尖銳的冰刺",
                "attact_type":  "wit",
                "damage_type":  "刺傷",
        ]),
        ([  "action":       "$N雙手連揮，數片銳利的薄冰飛向$n的$l",
                "attact_type":  "wit",
                "damage_type":  "割傷",
        ]),
        ([  "action":       "$N身形急旋，無數冰晶從$N身旁飛散開來，擊向$n",
                "attact_type":  "wit",
                "damage_type":  "凍擊傷",
        ]),
        ([  "action":       "$N右手輕揮，空中凝結出數條冰柱直落向$n的$l",
                "attact_type":  "wit",
                "damage_type":  "撞傷",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(HIW"雪女"NOR, ({"yukionna"}) );
  set("long",@LONG
雪女會在暴風雪的夜晚出現，會將不小心撞見她的人加以殺害，雖然
她是一位肌膚晶瑩剔透的白肌美女，但是只要被她的冰冷氣息吹到，
就會馬上急速冷凍，據說在荒郊野外，若是看到熊的話只要裝死就能
平安無事，萬一撞見了雪女的話，只要裝作沒看見就可逃過一劫喔！
LONG
);
  set("race", "人類");
  set("unit","位");
  set("age",130);
  set("attitude", "aggressive");
  set("gender", "女性" );
  set("level",45);
  set("Merits/wit",5);
  set("int",60);
  set_skill("unarmed",50);
  set_skill("dodge",70);
  set_skill("parry",30);
  add("addition_armor",80);
  set_temp("apply/hit",30);
  set_temp("apply/dodge",30);
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  carry_object(__DIR__"eq/ice-silk-cloth")->wear();
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
  if(!me || !target) return 0;
  if( !random(7) )
  {
    message_vision(HIC"雪女身上的"HIW"雪玉鐲"HIC"發出溫和的白光，治療了雪女的傷勢。\n"NOR,me);
    me->receive_heal("hp", 250);
  }
  if(me->is_busy()) return 0;
  if( !random(8) )
  {
    me->start_busy(2);
    target->add_busy(2);
    message_vision(HIW"\n雪女全身發出極大寒氣，使出"HIC"【冰鋒雪暴】"HIW"四周頓時颳起強風\n"
       +"夾帶著無數鋒利的冰片，往四面八方襲去！！\n\n"
       +"  ∴°"HIC"＊"HIW"．"HIC"※"HIW"° ．"HIC"＊"HIW"﹒°∴°"HIC"＊"HIW"．° ．﹒。∴°\n"
       +"  "HIC"※"HIW" ．﹒°∴° "HIC"※"HIW"．．﹒°∴°．"HIC"※"HIW"°"HIC"＊"HIW"°∴°\n"
       +"  °∴ ．∴．﹒°∴ "HIC"※"HIW"° ．﹒"HIC"＊"HIW"°∴°．°° \n"
       +"  ∴°．°"HIC"＊"HIW" ．﹒°∴°．°∴°．"HIC"＊※"HIW"° ．﹒\n"
       +"  °．"HIC"※"HIW"° ．"HIC"＊"HIW"﹒∴ ．∴．﹒°°．°°．"HIC"＊"HIW"  \n"
       +"  ．﹒°∴"HIC"＊"HIW"°．°∴°．"HIC"※"HIW"° ．﹒°∴°．° \n"
       +"  ．﹒°∴°"HIC"＊"HIW"．°．∴﹒°°°．∴﹒°∴"HIC"※"HIW"°\n\n"NOR,me);

    call_out("do_super",1,me);
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
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = 300 - (inv[i]->query_armor() ) +random(100);
      if( me->query("hp") < me->query("max_hp")/6 )
        damage = damage + random(100);
      if(damage<0) damage =0;
      message_vision(HIR"$N被銳利如刀刃的冰片割得全身傷痕累累．．．"HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      inv[i]->add_busy(2);
      COMBAT_D->report_status(inv[i]);
    }
  }
  me->start_busy(1);
  return;
}

varargs int receive_damage(string type, int damage, object who)
{
  int val;

  if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
  if( type!="hp" && type!="mp" && type!="ap" )
    error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
  if( objectp(who) && type=="hp")
    set_temp("last_damage_from", who);

  if(random(100)<30)
  {
    damage/=3;
    message_vision(HIW "\n$N口吐寒氣凝聚成一片冰盾，擋去了大半的傷害。\n" NOR,this_object());
  }
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
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
 
  switch( random(10) )
  {
    case  0..2:
          new(__DIR__"eq/ice-bracelet")->move(this_object());
          break;
  }
  ::die();
  return;
}
