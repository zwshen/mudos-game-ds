#include <ansi2.h>
inherit NPC; 
void summon_fox();
void create()
{
        set_name(HIW"九"HIY"尾"NOR,({ "killer fox", "fox" }) );
        set("level",60+random(20));
        set("race", "野獸");
        set("age", 1000+random(500));
        set("title",HIR"殺人狐"NOR);
        set("long", 
        "銀白色的皮毛和鮮紅的雙眼，想必就是傳說中的九尾狐。\n"
        "叫聲像嬰兒啼哭，人若受其蠱惑，難免遭厄運。不過人若\n"
        "吃了它的肉，也能不受妖邪之氣的侵害。九尾狐可幻化為\n"
        "美男美女，顛倒眾生。據說迷得商紂王身死國破的妲己，\n"
        "就是九尾狐所幻化。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("fox",1);
        set("max_hp",9000+random(5000));
        set("Merits/bar",8+random(5)); 
        set("Merits/wit",8+random(5));
        set("Merits/tec",1+random(10));
        set_skill("combat",100);
        set_skill("parry",90); 
        set_skill("dodge",100); 
        set_skill("unarmed",100);
        add("addition/armor",40);
        add("addition/damage",100); 
        add("addition/dodge",20);
        add("addition/hit",20);
        set("evil",2000);
        set("attitude", "aggressive");  
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
        (: summon_fox() :),
         }) );
        setup(); 
        carry_object(__DIR__"eq/fist2")->wield();
}
int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(!random(5))
  {
    message_vision("\n$N"HIW"釋放出大量"NOR+MAG"妖氣"HIW"後，$N"HIW"的"NOR+MAG"妖氣"HIW"開始產生了變化•••\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  return 0;
}
void do_super(object me)
{
  // 這裡的 me 是指 this_object()
  object *inv;
  object ob;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]))
    {
      if( inv[i]->query("fox") ) continue; 
      if( inv[i]->query_temp("invis")>2) continue;
      switch(random(100)){
      case 0..50:
       damage = me->query("mp");
message_vision(HIW"\n一股妖氣竄入$N"HIW"體內，$N"HIW"的精氣被$n"HIW"給吸食了！！"HIY"("+damage+")\n"NOR,inv[i],me);
       inv[i]->receive_damage("hp", damage, me); 
       inv[i]->start_busy(random(2));
       COMBAT_D->report_status(inv[i]);
       me->add("hp", damage);
       me->receive_damage("mp",random(30));
       break;
      case 51..75:
       damage = (me->query("ap"))/10;
message_vision(HIW"\n一股妖氣竄入$N"HIW"體內，$N"HIW"的魔力被$n"HIW"給吸食了！！"HIY"("+damage+")\n"NOR,inv[i],me);
       inv[i]->receive_damage("mp", damage, me);
       COMBAT_D->report_status(inv[i]);
       inv[i]->start_busy(random(2));
       me->add("mp", damage);
       me->receive_damage("mp",random(30));
       break;
      default:
       damage = (me->query("hp"))/100; 
message_vision(HIW"\n一股妖氣竄入$N"HIW"體內，$N"HIW"的內勁被$n"HIW"給吸食了！！"HIY"("+damage+")\n"NOR,inv[i],me);
       inv[i]->receive_damage("ap", damage, me);
       COMBAT_D->report_status(inv[i]); 
       inv[i]->start_busy(random(2));
       me->add("ap", damage);
       me->receive_damage("mp",random(30));
      break;
      }
    }
    else
    {
      message_vision(HIR"\n$N被"HIW"九"HIY"尾"NOR"的妖氣燃燒殆盡了.. \n\n"NOR,inv[i]);
      me->add("hp", 100);
      destruct(inv[i]);
    }
  }
  return;
}  

int receive_damage(string type,int cost)
{
  object ob,me;
  int i;
  ob = this_object();
  me = this_player();

  // 反擊
  if(!random(4))
  {
    if(ob->is_busy()) ob->add_busy(-10);
    message_vision(HIW"\n【"HIR"九尾的反擊！"HIW"】\n"NOR,ob);
   
 if(me->query("level") > 40)
    {
      COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+3);
      if(query("hp") < query("max_hp")) add("hp",60+random(40));
    }
    else
      if(me->query("level") > 30) 
      {        COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+2);
         if(query("hp") < query("max_hp")) add("hp",15+random(15));
      }
      else
if(me->query("level") > 24)
        {
          COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),(random(2)+2));
        }
        else
          COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),(random(2)+1));
  }

  ::receive_damage(type,cost,me);
  return 0;
}  
void summon_fox()
{
  int hp,max_hp;
  object b,ob1,me;
  me=this_object();
  hp=this_object()->query("hp");
  max_hp=this_object()->query("max_hp");

  if( hp < (max_hp - 5000) )
  {
    b=new(__DIR__"s_fox" );
    b->move(environment(this_object()));
    message_vision(HIG"\n$N的妖氣漸漸凝聚成形，跑出了一隻$n••\n",this_object(),b);
    b->kill_ob(this_object());
    this_object()->kill_ob(b);    return;
  }
}

void die()
{
object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", 
        
        HIW"\n\t【"HIB"神　　話"NOR+HIW"】
        "HIW"\n\t殺人無數的"HIR"殺人狐 九尾"NOR+HIW"終於被"NOR+ob->name(1)+HIW"封印了•\n\n"+NOR,users());
        ob->add("popularity",10);
        tell_object(ob,HIG"\t你得到了１０點聲望！\n"NOR);
        message_vision( "\n\t$N"+HIR "臨死前，因為妖氣用盡，身上毛皮脫落下來....\n" NOR ,this_object() );
        newob=new(__DIR__"obj/pe"); 
        ob->set_temp("ko_fox_nine",1);
"/open/world1/whoami/birdarea/fox18"->set("exits");
"/open/world1/whoami/birdarea/fox19"->delete("exits","out"); 
"/open/world1/whoami/birdarea/fox19"->add("exits",
(["back" : "/open/world1/whoami/birdarea/village1.c"]));
        newob->move(environment(this_object() ) );
        ::die();
        return;
} 

