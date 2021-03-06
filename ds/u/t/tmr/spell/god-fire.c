//god-fire 神武真火 (神武教初級法術-火系)

#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target)
{
 int inn,sk,cost,lev;
 int lv,mk,lck;
 string who,name;
 
 if(!me) me=this_player();
 inn=me->query_int();
 lev=me->query("level");
 mk=me->query_spell("god-fire");
 sk=mk/10+1;

 if ( !me->is_fighting())
    return notify_fail("「神武真火」只有戰鬥時才能使用。\n");

 if ( !target ) target = offensive_target(me);
 if ( !target||!objectp(target = present(target, environment(me)))||target==me )
 	return notify_fail("你要對誰施展這個法術﹖\n");
 if(	!target->is_character()
	||	target->is_corpse()
	||	target->is_ghost())
	{
		return notify_fail("此項法術只能對生物使用。\n");
	}

	if(userp(me) && userp(target))
	{
	  if(me->query("level") < 5 ) return notify_fail("你目前的等級不可以攻擊玩家﹗\n");
	  if(target->query("level") < 5 ) return notify_fail("你不可以攻擊如此低等級的玩家﹗\n");
	  if(me->query("level") > target->query("level") + 5 ) return notify_fail("你不可以攻擊等級相差太多的玩家﹗\n");
	  if(me->query("level") < target->query("level") - 5 ) return notify_fail("你不可以攻擊等級相差太多的玩家﹗\n");
	}
 if( (int)me->query("mp") <  cost )
	    return notify_fail("你的法力不夠。\n");
 message_vision(HIG"\n$N雙手合十，喃喃自語道：「天地合德，日月合明，四時合序，鬼神合火以滅敵。」\n"NOR,me);
  me->start_busy(2);
  call_out("delay",3,target,me,mk);
  return 1;
}

int delay(object target,object me,int mk)
{
 int tlv,inn,lv,sk,i,damage,cost;
							
 if(!me) return 0;					
 if(!target) return notify_fail("目標消失了。\n");	
 if( environment(me) != environment(target) )		
	  return notify_fail("目標離開了你的施法範圍。\n");
 sk=mk/20+random(mk/20)+1;
 cost=(mk/5)+10;
 inn=me->query_int();
 lv=me->query("level");
 message_vision(HIR"\n突然$N手上烈焰衝天,不知從何引起一道「神武真火」！！\n\n"NOR,me);

 tlv=target->query("level");

 if( lv + random(inn) + inn > tlv+ random(inn) )
 {
    message_vision(HIG"\n$N默念一聲「滅」，隨即祭起手上真火直燒向$n！！\n\n"NOR,me,target);
    damage=( inn +random(mk) );
    damage -= target->query_sheild();
    damage -= target->query_skill("dodge")/10;

    me->receive_damage("mp",cost);

    if ( damage > 0)
    {
       message_vision(HIC"只見$N閃躲不掉一道「神武真火」的攻勢，被燒得皮開肉綻！\n"NOR,target);
       target->receive_damage("hp", damage, me ); 
       target->start_busy(2);
    }
    else
	{
       message_vision(GRN"只見$N東閃西躲，好不容易躲開一道「神武真火」的猛烈攻勢。\n"NOR,target);
	}
 }


 if( inn>random(20) )
 {
         me->improve_spell("god-fire",inn+random(20));
 }
	 if(!target->is_fighting(me)) target->kill_ob(me);
	 if(!me->is_fighting(target)) me->kill_ob(target);
	 return 1;
}
