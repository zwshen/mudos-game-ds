#include <ansi.h> 
inherit NPC;    

void create()
{
  set_name(HIR"烈燄彈"NOR, ({"fire ball","ball"}) );
  set("long","伊佛利特所吐出的高熱火球。\n");
  set("unit","顆");
  set("level",40); 
  set("age",0);
  set("max_hp",30000);
  setup(); 
  call_out("dest_ball", 2+random(3));
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
}

int special_attack(object me,object target,int hitchance)
{
  object *inv;
  int damage,dex_r,block_r,i;
  inv = all_inventory(environment(me));
  if(!me || !inv) return 0;
  message_vision("\n$N"HIW"疾速的在四周橫衝直撞，迸射出無數火星！\n"+NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( living(inv[i]) && userp(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      damage = random(100)+450-(inv[i]->query_shield())-(inv[i]->query_armor()/2);
      if(damage < 0) damage=0;
      dex_r=random(inv[i]->query_dex());
      block_r=random(inv[i]->query_skill("block"));
      if( dex_r > 50 )
      {
        message_vision(HIG"$N眼明腳快，躲過烈燄彈的攻擊。\n"NOR,inv[i]);
      }
      else if( block_r > 70 && inv[i]->query_temp("armor/shield") )
      {
        message_vision(HIG"$N及時以盾牌硬是擋住烈燄彈的衝擊，烈燄彈與盾牌撞擊激出火星四濺。\n"NOR,inv[i]);
      }
      else
      {
        message_vision(HIR"$N被烈燄彈正面擊中，造成 ("+damage+") 點的內傷及灼傷！\n"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage, me);
        COMBAT_D->report_status(inv[i]);
      }
    }
  }
  return 1; 
}    

void dest_ball()
{
  destruct(this_object());
}