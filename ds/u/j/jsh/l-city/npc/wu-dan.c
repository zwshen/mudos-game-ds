#include <path.h>
#include <ansi.h>
inherit NPC;

void heal();
void create()
{
  set_name(HIW"梧丹三世"NOR,({"wu-dan","dan"}) );
  set("long", HIW"
  開羅國的國君王，統領著巨大的開羅長城，\n"
 "  手中的兵力，可與東大陸的泰源天國媲美。\n"NOR    
  );
  set("race", "human");
  set("unit","位"); 
  set("title",HIG"開羅國王"NOR);
  set("age",60);
  set("level",65);
  set("attitude", "friendly");
  set("max_hp",30000);
  set("Merits/bar",5);
  set("Merits/bio",5);
  set("Merits/wit",5);
  add("addition_armor",123);
  add("addition_damage",123);
        set("chat_chance",7);
        set("chat_msg",({
  (: heal :),  
}));

  setup();
  carry_object(__DIR__"obj/blade")->wield();
}

void heal()
{ 
  if(query("hp") > query("max_hp")) return;  
  add("hp",500); 
  return;
}   
int special_attack(object me, object target, int hitchance)
{ 
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(9))
  { 
    me->start_busy(2);
    target->add_busy(1);
    message_vision(HIW"\n$N忽然眼爆白光！一條巨大"+HIW""+BLK"氣蛇"+HIW"從$N天靈衝出！\n\n"NOR,me);
    call_out("do_super",2,me);
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

  message_vision(HIW"\n巨大氣蛇張開大口！一股"+BLK"黑色能量"+HIW"慢慢凝聚！噴出！\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]))
    {
      damage = random(400)+250;
      message_vision(HIW"$N被"+BLK"『開羅•氣蛇波』"+HIW"掃過 .... 全身散出"+HIR"濃濃血氣味.."HIM"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIC"\n$N像分子一樣的，瞬間散開，飄飄然於空氣之中 .... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(1);
  return;
}

void die()
{
   object ob,obj;
   obj=new(__DIR__"/obj/money/coin");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
    HIG"\n【"+HIB"開羅捷報"+HIG"】"+HIY""+ob->name(1)+"單槍匹馬，英雄似的，打下了"+HIB"開羅長城。\n\n"+NOR     
       ,users());
        ob->add("popularity",7+random(3)); 
        ::die();
        return;
}


