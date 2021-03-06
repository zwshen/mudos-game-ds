#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(HIW"天叢"HIC"雲劍"NOR, ({ "kusanagi sword","sword" }) );
  set("long",@long
由八歧大蛇的尾巴中取得，因八歧大蛇出沒時上空常有烏雲蓋日而得
名，又名草薙之劍，是天下無雙的神劍。
long);      
  set_weight(1450);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "blacksteel");
    set("value",30000);
    set("volume",4);
    set("rigidity",1200);
    set("limit_skill",60);
    set("limit_lv",45);
    set("replica_ob",__DIR__"viper-killed-katana");
  }
  set("weapon_prop/con",3);
  init_sword(70);
  set("wield_msg",HIC"$N拔出$n"HIC"，瞬間天空一陣風雲急湧，隨後又回歸平常。\n"NOR);
  set("unwield_msg","$N以絹布擦拭$n的劍刃後，小心地收起。\n");
  setup();
}

void attack(object me,object victim)
{
  int hitchance;
  ::attack();
  if(!me) return;
  if(!victim) return;
  if( me->query("ap") < 250 ) return;
  if( me->query("level") < 35 ) return;
  
  hitchance = me->query("level")/10 + me->query_dex()/10;
  if(!random(21-hitchance))
  {
    me->start_busy(2);
    message_vision(HIC"\n天叢雲劍的劍刃流轉藍光，$N的周圍漸漸凝聚淡淡的雲氣，突然劍光如白晝般照射四周！！\n"NOR,me);
    call_out("do_super",2,me);
    return;
  }
  return;
}

void do_super(object me)
{
  object *inv;
  int i, damage,def;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIW"\n光芒聚成巨大無比的劍刃，$N如神人般浮在半空迅速地將劍刃往四周橫掃斜劈。！！\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(inv[i]->query("no_fight")) continue;
    if(inv[i]->query("no_kill")) continue;
    if( inv[i]->query_temp("invis")>2 ) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if(inv[i]->is_fighting(me))
      {
        def=inv[i]->query_skill("parry")+inv[i]->query_skill("dodge")+inv[i]->query_skill("block");
        damage = 200+random(100)+me->query_skill("sword")+me->query_str()-def;
        if(damage < 1)
        {
          message_vision(HIG"$N連閃帶避，辛苦地躲過攻勢！\n"NOR,inv[i]);
        }
        message_vision(HIR"$N被劍光直接斬中，受到嚴重的創傷！"HIR"("+damage+")\n"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage, me);
        COMBAT_D->report_status(inv[i]);
      }
      else
      {
        def=inv[i]->query_skill("parry")+inv[i]->query_skill("dodge")+inv[i]->query_skill("block");
        damage = 200+random(50)+me->query_skill("sword")+me->query_str()-def;
        damage=damage/5;
        if(damage < 1)
        {
          message_vision(HIG"$N慌忙閃躲，險些遭到劍光波及！\n"NOR,inv[i]);
        }
        message_vision(HIR"$N無辜地被劍光掃中，受到輕微的割傷！"HIR"("+damage+")\n"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage, me);
      }
    }
  }
  me->start_busy(1);
  me->receive_damage("ap",100);
  return;
}
