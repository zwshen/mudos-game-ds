//god-fire 神武真火 (神武教初級法術-火系)

#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target)
{
 int inn,sk,cost,mk,busy;
 
 if(!me) me=this_player();
 inn=me->query_int();
 mk=me->query_spell("god-fire");
 sk=mk/10+1;
 cost=(mk/3)+10+random(me->query("level"));
 
 if(environment(me)->query("no_cast")) return notify_fail("這裡不能施法。\n");
 
 if ( !target ) target = offensive_target(me);
 if ( !target ) return notify_fail("你要對誰施展這個法術﹖\n");

        //檢查是否可以攻擊
 if(!me->can_fight(target))
                return me->can_fight(target);

 if( (int)me->query("mp") <  cost )
            return notify_fail("你的法力不夠。\n");
 message_vision(HIG"\n$N雙手合十，喃喃自語道：「天地合德，日月合明，四時合序，鬼神合火以滅敵。」\n"NOR,me);
 busy=2;
	me->start_busy(busy); //施法動作時間
	me->receive_damage("mp",cost); //施法扣MP
	me->set_temp("power_cast",1+mk/33);

	if(userp(me)) 
		call_out("delay",busy*2-1,target,me,mk);
	else 
		call_out("delay",busy*2-2,target,me,mk);
 return 1;
}


int delay(object target,object me,int mk)
{
int inn,sk,damage,shield,level;

 if(!me) return 0;                                      
 if(!target) return notify_fail("目標消失了。\n");      
 if( environment(me) != environment(target) )           
          return notify_fail("目標離開了你的施法範圍。\n");
 if( me->query_temp("power_cast") < 1) 
 {
  message_vision(
	HIW"$N"HIW"因為受到創傷而亂了思緒, 無法順利施展法術。\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 sk=mk/20+random(mk/20)+1;
 inn=me->query_int();
 level=me->query("level");
 shield=target->query_shield();

    damage = mk+inn*3+level;
    damage = damage/2 + random(damage/2);
    if(userp(me))	damage=damage+(damage/4)-random(damage/8);
    damage = damage - shield/2 -random(shield/2);
    if(userp(target)) 	damage=damage-damage/5;
    if(damage<1)	damage=random(inn+mk/3);

 message_vision(
HIR"\n突然$N手上烈焰衝天，祭起一道「神武真火」直燒向$n！！\n"NOR
,me , target);

if(damage > 0)
 {
    // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)

	if( inn + random(mk*2 + inn*2)  > random(-COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int()))
    {
        // 增加素質對傷害的影響
        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
       target->receive_damage("hp", damage, me );
       message_vision(HIC "$N閃躲不掉一道「神武真火」的攻勢！\n"NOR,target);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	        tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
	        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->qu
ery("max_hp")+")");
       message_vision("\n",target);
       if(wizardp(me) && me->query("env/debug")) tell_object(me,"  造成"+damage+"點傷害!!\n");
       COMBAT_D->report_status(target);         //顯示target狀態
	}
    else
        {
                message_vision(GRN"只見$N東閃西躲，好不容易躲開一道「神武真火」的猛烈攻勢。\n"NOR,target);
        }
 } else message_vision(GRN" 「神武真火」猛烈的燒向$N, 但似乎沒有造成$N絲毫的傷害。\n"NOR,target);

 if( random(40+inn) > 20 )
 {
         me->improve_spell("god-fire",inn/2+random(inn)+1);
 }
 if(random(2+mk/25)==0) me->start_busy(1);
 if(!target->is_fighting(me)) target->kill_ob(me);
 if(!me->is_fighting(target)) me->kill_ob(target);
 if(random(8)<1) me->add_busy(1);

//二連發
if(me->query_spell("god-fire")>89 && random( inn ) > random( -(COMBAT_D->dodge_factor(target,"dodge")/2 )  ) )
	{
		call_out("delay2",2+random(5),target,me,mk);
	}

return 1;
}

int delay2(object target,object me,int mk)
{
 int inn,sk,damage,shield,level;
                                                        
if(!me) return 0;
if(!target) return notify_fail("目標消失了。\n");
if( environment(me) != environment(target) )
          return notify_fail("目標離開了你的施法範圍。\n");

sk=mk/20+random(mk/20)+1;
inn=me->query_int();
level=me->query("level");
shield=target->query_shield();
    damage = mk+inn*3+level;
    if(userp(me)) damage=damage+(damage/4)-random(damage/8);
	    damage = ( damage - shield/2 -random(shield/2) ) /2 + random(me->query_spell("god-fire"));
   if(userp(target)) damage=damage-damage/5;

message_vision(HIR"剎那間！！$N的背後出現一條噬面火龍，飛騰而出，直衝向$n！！\n"NOR,me,target);

 if(damage > 0)
 {
    // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)
   // 增加素質對傷害的影響
        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
        target->receive_damage("hp", damage, me ); 
        message_vision(HIR"$N慘叫一聲，整個身軀被火龍一口所吞噬！！"NOR,target);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	        tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
	        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
        message_vision("\n",target);
        if(wizardp(me) && me->query("env/debug")) tell_object(me,"  造成"+damage+"點傷害!!\n"); 
        COMBAT_D->report_status(target);         //顯示target狀態
    }
    else
	{ message_vision(GRN"只見火龍猛然的吞噬著$N，但似乎沒有造成$N絲毫的傷害。\n"NOR,target); }
 
if( random(40+inn) > 20 )
 {
         me->improve_spell("god-fire",inn/2+random(inn)+1);
 }
	 if(random(2+mk/25)==0) me->start_busy(1);
	 if(!target->is_fighting(me)) target->kill_ob(me);
	 if(!me->is_fighting(target)) me->kill_ob(target);
}
