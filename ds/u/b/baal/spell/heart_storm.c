//god-fire 神武真火 (神武教初級法術-火系)

#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target)
{
 int inn,sk,cost,mk;
 
 if(!me) me=this_player();
 inn=me->query_int();
 sk=mk/10+1;
 cost=(mk/3)+10;
 
 if(environment(me)->query("no_cast")) return notify_fail("這裡不能施法。\n");
 
 if ( !target ) target = offensive_target(me);
 if ( !target )	return notify_fail("你要對誰施展這個法術﹖\n");

	//檢查是否可以攻擊
 if(!me->can_fight(target))
		return me->can_fight(target);

 if( (int)me->query("mp") <  cost )
	    return notify_fail("你的法力不夠。\n");
	    
 message_vision(HIG"\n$N雙手高舉, 大喝一聲：『願塔沙達與我同在！！』\n"NOR,me);
 me->start_busy(2); //施法動作時間
 me->receive_damage("mp",cost);	//施法扣MP
 me->set_temp("power_cast",2+mk/20);
 call_out("delay",3,target,me,mk);
 return 1;
}

int delay(object target,object me,int mk)
{
	
 int inn,sk,damage;
							
 if(!me) return 0;					
 if(!target) return notify_fail("目標消失了。\n");	
 if( environment(me) != environment(target) )		
	  return notify_fail("目標離開了你的施法範圍。\n");
 if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1) 
 {
  message_vision(HIW"$N"HIW"因為受到創傷而亂了思緒, 無法順利施展心靈風暴。\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 sk=mk/20+random(mk/20)+1;
 inn=me->query_int();
 
 message_vision(HIR"\n突然$N手中出現一個巨大的光球，令人不敢直視！！\n\n"NOR,me);
 message_vision(HIG"\n$N大喝一聲：『神民的敵人，受死吧！』隨即將手上光球祭向天空！！\n\n"NOR,me,target);

    damage= inn +random(mk+inn);
    damage = damage- target->query_sheild()/2 -random(target->query_sheild());
    if(damage<1) damage=random(inn/2);

 if(damage > 0)
 {
    // COMBAT_D->dodge_factor(target,"dodge") 會傳回對方閃躲率(負值)
    if( inn + random(mk*2 + inn*2)  > random(-COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int()))
    {
       message_vision(HIC"  只見$N被天上包下的電網包住, 痛苦的掙扎著！！"NOR,target);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
	tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       if(wizardp(me) && me->query("env/debug")) tell_object(me,"  造成"+damage+"點傷害!!\n"); 
       target->receive_damage("hp", damage, me ); 
       COMBAT_D->report_status(target);		//顯示target狀態
       target->start_busy(1);
    }
    else
	{
                message_vision(GRN"  只見$N東閃西躲，好不容易逃離『心靈風暴』的範圍。\n"NOR,target);
	}
 } else message_vision(GRN"  只見「心靈風暴」狠狠的包住$N, 但似乎沒有造成$N絲毫的傷害。\n"NOR,target);


 if( random(40+inn) > 20 )
 {
         me->improve_spell("god-fire",inn/2+random(inn)+1);
 }
 if(!target->is_fighting(me)) target->kill_ob(me);
 if(!me->is_fighting(target)) me->kill_ob(target);
 return 1;
}
