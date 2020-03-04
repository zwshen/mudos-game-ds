// 原為 MD 的 mob, 設定與DS 不同, 請勿參考
#include <ansi.h>
inherit NPC;
inherit SSERVER;
void create()
{
set_name("[1;30m歐坦[0m",({"swordsoul oten","oten"}));
set("title","[1;34m劍魂[m");
set("level",60);
set("age",500);
set("war",1);
set("evil",200+random(200));
set("long","你看到一具黑色的鎧甲騎在一匹駿馬上，絲毫沒有生命的跡象。\n\n");
set("chat_chance",10);
//set("attitude", "aggressive");
set("chat_msg",({
(:command,"say":) ,
"劍魂 歐坦發出一陣陣低沉的呻吟.....嗚..啊啊啊........\n",
}) );
add_temp("apply/armor",70);
add_temp("apply/damage",70);
 setup();
}

int filter_listener(object ppl)
{
        if( !environment(ppl) ) return 0;
        if( ppl->money_type() != this_object()->money_type() ) return 0;
        return 1;
}

void heart_beat()
{
 object target,me,ob,ot;
 int damage,damage2;
 int i;
 me = this_object();
 ::heart_beat();
 if(!me) return;
 if( me->is_fighting() )
 {
  target = offensive_target(me);
  if(!target) return;
  if(environment(me)!= environment(target) ) return;
  if(random( target->query_dex() ) < 10  )
  {
   damage=200+random(400);
   damage2 = target->query("hp")/5;
   if(damage2 < 100) damage2 = 50+random(100);
   if(target->query_temp("slash")<1)
   {
   message_vision(HIR"\n\n 　 給..給我∼∼∼血∼啊∼∼哈∼哈∼∼哈∼∼哈∼∼∼\n",me);
   message_vision(@DIE
                       ______
                    .-"      "-.
                   /            \
       _          |              |          _
      ( \         |,  .-.  .-.  ,|         / )
       > "=._     | )(__/  \__)( |     _.=" <
      (_/"=._"=._ \/     /\     \/ _.="_.="\_)
             "=._"(_     ^^     _)"_.="
                 "=\__|IIIIII|__/="
                _.="| \IIIIII/ |"=._
      _     _.="_.="\          /"=._"=._     _
     ( \_.="_.="     `--------`     "=._"=._/ )
      > _.="                            "=._ <
     (_/                                    \_)
DIE
,me);
   message_vision("\n[1;30m劍魂 歐坦高舉長劍向$N[1;30m的方向策馬衝去!![m\n",target);
   message_vision(HIW"∼瞬間黑暗中劃過一道光芒∼ $N"HIW"的臉色一片慘白!! "HIR"("+damage2+")\n"NOR,target);
   target->receive_damage("hp",damage2,me);
   target->set_temp("slash",3);
   } else
    {
     message_vision(HIB"\n\n劍魂狂笑道: 給..給我∼∼∼"HIR"血∼啊∼∼哈∼哈∼∼哈∼∼哈∼∼∼\n",me);
     message_vision(HIR"$N"HIR"身上的劍痕不斷的流出一波波鮮血..("+damage+")\n"NOR,target);
     target->receive_damage("hp",damage,me);
     target->add_temp("slash",-1);
    }
   } 
 }
}

void die()
{
 object ob,ob1,a,ob2,owner,*user;
 int expp;
 ob = query_temp("last_damage_from");
 if(!ob) ob = this_player(1);
 owner=ob->query("creater");
 if(owner) ob=owner;
 if(ob)
 {
 	user = filter_array( users(), "filter_listener", this_object() );
	message("system",HIC"\n\n蟄伏了五個世紀的 劍魂 歐坦 終於被"+ob->query("name")+HIC"封印於魔劍之中了!!\n\n"NOR,user);
 }

  if(!a = environment(this_object())) { destruct(this_object()); return; }
  message_vision("\n[1;37m劍魂 歐坦的身形逐漸化為一把劍的形狀..[m\n",this_object());
  
  ob1=new(__DIR__"wp/otensword.c");
  ob1->move(a);
  expp=50000-(ob->query("level")*(500+random(500)));
  if(expp<1) expp=random(17000);
  ob->add("exp",expp);
  tell_object(ob,"\n你得到了"+expp+"點經驗值.\n");
  ob->set_temp("killoten",1);
  ob->save();
  destruct(this_object());
 
}
