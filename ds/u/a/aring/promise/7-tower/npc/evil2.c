#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(WHT"勤及"NOR, ({"qin xin","xin"}) );
  set("long",@LONG
在大約十年前，江湖出了一位善於剛柔拳的少俠，就連拳法之家
八極門上上下下都不比這位少俠，但不知何緣故，這位少俠突然
消失在江湖上，今日著了魔道，一定有原因。
LONG
);
  set("gender", "男生");  
  set("race", "人類");
  set("age",31);
  set("level",48);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",HIC"百年"NOR+CYN"妖客"NOR); 
  set("Merits/bar",13);
  set("Merits/bio",10);
  set("Merits/wit",1);
  set("Merits/tec",10);
  add("addition_damage",200);
  add("addition_armor",100);
  set("max_hp",10500);
  set("chat_chance", 30); 
  set("chat_chance_combat",80);
  set("chat_msg_combat",({
  (: command("do wield claw") :),
  (: command("do wield claw") :),
  (: command("do wield claw") :),
 (: command("do wield claw") :),
 (: command("do wield claw") :),
 (: command("do wield claw") :),
 (: command("do wield claw") :),
 (: command("do wield claw") :),

}));

  setup();
  carry_object(__DIR__"eq/eq2")->wear();
  carry_object(__DIR__"wp/wp2")->wield();
 }

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;

  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") > 40 && userp(this_player()) )
    this_object()->kill_ob(this_player());

  
}
int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))
  {
    me->start_busy(1);
    target->add_busy(2);
    message_vision(HIY"\n$N"HIY"站踏弓步，雙手操於腰部，蓄勢待發準備使出剛拳秘傳『百虎咆嘯』！！\n"NOR,me);
    call_out("do_super",2,me);
    return 1;

}
 
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
      damage = 250+random(200);
      message_vision(HIR"\n$N被剛烈的剛拳擊中要害，當場倒地痛不欲身！！........ "HIR"("+damage+")\n\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIC"\n$N使出輕盈的輕功\，躲開此攻擊！！\n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(1);
  return;
} 
void die()
{
  object ob,env;
   int temp;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  env = environment(ob);
  temp = NATURE_D->which_world(env);
  message("world:world1:vision", "\n\t"HIW"就在" +NATURE_D->game_time(temp)+"       
  "NOR+CYN"\n\n\t七邪塔傳來聲哀號....縱橫七邪塔第二層 "WHT"勤及 "HIW"敗在"HIY+ob->query("name")+HIW"手上\n\n"+NOR
       ,users());
  ob->add("popularity",5);      
  tell_object(ob,HIY"消滅了妖邪，佛祖大開法恩賞賜你三點聲望以此嘉獎。"NOR);
    switch( random(50) )

  {

    case  0..25: new(__DIR__"obj/book")->move(ob);
          break;
    case  26..50: new(__DIR__"obj/gold-box")->move(this_object());

          break;
    }
  
   ::die();
  return;
}


