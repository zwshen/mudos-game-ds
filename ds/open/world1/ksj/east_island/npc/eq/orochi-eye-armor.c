#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(GRN"蛇"HIR"眼"GRN"護甲"NOR ,({ "orochi-eye armor","armor" }) );
  set("long",@LONG
八岐大蛇的眼球不同一般，在表面已突變成堅硬的構造，所以能承受
極高能量的八岐邪光，這個護甲是大蛇死後眼睛剛好破碎成可以用來
穿著當作護甲的形狀，通常大蛇死後眼球不是燒毀就是變成碎片，能
當作護甲的當真少之又少。
LONG);
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",4);
    set("unit", "件");
    set("value",25000);
  }
  set("limit_con",50);
  set("limit_lv",40);
  set("armor_prop/armor",35);
  set("armor_prop/con",2);
  set("armor_prop/wit",1);
  set("armor_prop/bar",-1);
  set("armor_prop/dex",-3);
  set("armor_prop/dodge",-10);
  call_out("receive_by_eye", 30);
  setup();
}

void receive_by_eye()
{
  object me = environment(this_object());
  int p_ap,p_hp,p_mp,i,hl;
  hl=0;
  if( !this_object() || !me ) return;
  if( me->query_temp("armor/body")==this_object() )
  {
    p_hp = me->query("max_hp");
    p_ap = me->query("max_ap");
    p_mp = me->query("max_mp");

    if( me->query("hp") < (p_hp-200) )
    {
      me->receive_heal("hp", 150);
      hl = hl+1;
    }

    if( me->query("ap") < (p_ap-100) )
    {
      me->receive_heal("ap", 70);
      hl = hl+1;
    }

    if( me->query("mp") < (p_mp-100) )
    {
      me->receive_heal("hp", 70);
      hl = hl+1;
    }

    if(hl > 0)
    {
      message_vision(HIR"\n$N突然吸收周圍的能量，漸漸地呈現亮紅色，一股強大的力量\n"
           +"源源不絕地匯入$n身體中。....\n"NOR, this_object(), me);
    }
  }
  call_out("receive_by_eye", 35);
}
