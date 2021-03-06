#include <ansi.h>
#include <weapon.h>

inherit SWORD;
void create()
{
  set_name( "雙手劍" , ({ "two-hand sword","sword" }) );
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "這是由鐵製成的雙手劍，看起來比較笨重。\n");
    set("material", "iron");
    set("value",1500);
    set("volume",1);
  }
    set("limit_str",15);
  init_sword(30,TWO_HANDED);

  set("wield_msg","$N從背後抽出一把雙手劍，$N覺得熱血沸騰！\n");
  setup();
}

int wield()
{
  object me;
  me = this_player();
  if(me->query("combat_exp") < 150 )
  { return notify_fail("你經驗不足，無法使用雙手劍。"); }
  else { return ::wield(); }
}

void attack(object me,object victim)
{
        int freeztime,def;

        ::attack();
        if(!me) return;
        if(!victim) return;
    if(me->query_skill("sword") > 50 && me->query_str() > 20 && random(25)<3 )
    {
        message_vision( 
                HIC "\n只見$N"+HIC "拿起手中的雙手劍，往$n的頭上砸下去！！\n" NOR
    ,me,victim);

        freeztime = random(me->query_str()/4)+4;
        def = victim->query_con()/2;
        if(me->query("ap") < 10)
        {
        message_vision("$N"+HIG+"氣力不足，軟趴趴的熱血不起來。\n"NOR,me);
        return;
        }
        if(freeztime-def>4)
        {
        me ->start_busy(2);
        victim->start_busy(freeztime);
        message_vision(HIW+victim->query("name")+HIW"被$N以雙手劍砸中，暈眩了一下。\n\n"NOR,me);
        me->add("ap",-8);
        }
        else
        {
        message_vision(NOR"$N往旁邊一跳，閃過了$n的攻勢。\n"NOR,victim,me);
        }
    }
    return;
}
