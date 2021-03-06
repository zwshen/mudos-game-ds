#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name(HIM"櫻亂舞"NOR, ({ "sakura-ranbu katana","katana" }) );
  set("long",@long
淡紅色刀鞘的長刀，刀刃呈現美麗的櫻花紋，一般的鍛造刀劍的方式
並無法製作的出，據說鬼人  秋川．旭於櫻花林中演武時一刀橫斬向
一棵櫻花樹，手中太刀居然應聲而斷，於是在樹中發現此刀。
long);      
  set_weight(1650);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "blacksteel");
    set("value",30000);
    set("volume",3);
  }
  set("rigidity",1200);
  set("limit_skill",60);
  set("limit_lv",33);
  set("weapon_prop/int",2);
  set("weapon_prop/con",1);
  set("weapon_prop/bio",-1);
  set("replica_ob",__DIR__"ya-katana");
  init_blade(63);
  set("wield_msg","$N緩緩拔出$n，刀光映照在四周有如片片櫻花飄落。\n"NOR);
  set("unwield_msg","$N將手中的$n放回刀鞘，發出--鏗--一聲清響。\n");
  setup();
}

void attack(object me, object victim)
{
  int damage,def;
  ::attack();
  if(!me) return;
  if(!victim) return;

  if(me->query_int() > 40 && random(10)<3 )
  {
    message_vision(HIM"\n空中突然飄下櫻花花瓣在$n的周圍旋舞，遮敝了$n的視線．．．\n"NOR,me,victim);
    damage += (me->query_skill("blade"))/2+me->query_str()+random(50);
    def += victim->query_skill("parry")+victim->query_skill("dodge")+victim->query_dex()+victim->query_con();
    def = def/4;
    if(damage-def>0 && random(10)>4)
    {
      damage=damage+random((damage-def));
      message_vision(HIR"$N突然感到一陣劇痛，身體已被直接斬中，鮮血直流！！"HIR"("+damage+")\n"NOR,victim);
      victim->receive_damage("hp",damage, me);
      me->receive_damage("ap",30);
      damage=damage-random(100)+30;
      if(me->query_dex() > 70 && !random(5) && damage >0)
      {
        message_vision(HIR"刀光快速迴旋逆斬，$N的背後又被刀刃劃過！！"HIR"("+damage+")\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
        me->receive_damage("ap",30);
      }
      damage=damage-random(100)+10;
      if(me->query_dex() > 90 && me->query_str() > 90 && !random(5) && damage>0)
      {
        message_vision(HIR"刀光快速迴旋逆斬，$N的背後又被刀刃劃過！！"HIR"("+damage+")\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
        me->receive_damage("ap",30);
      } 
    }
    else
    { 
      message_vision(HIW"一道刀光劈向$N，但是偏了一點沒有命中。\n"NOR,victim);
      me->receive_damage("ap",20);
    }
  }
  return;
}
