/*****************************************************/
/* WIND CLASS NEW SKILL          DATE:2003.5.24      */
/* EDITOR:Jangshow               NOTE:NO WEAPON SK   */ 
/* 一段時間後,看ppl的反應,再看要不要開御劍           */
/*****************************************************/
#include <ansi.h>
#define SKILL_NAME "索星奧義"
inherit SKILL;
inherit SSERVER; 
mapping *action = ({ 
([
   "action": "$N屈劍一指，內力潛進劍中，使出"HIC"「"HIR"煜"HIC"」"NOR"字訣，劍招狠狠的斗直直進",
   "damage":       100+random(99),  //這個是傷害強化的百分比 , 不是傷害點數
   "attack":       10,
   "attact_type":  "tec",  // 設定技能的攻擊種類 // 生物(bio) 獸性(bar) 魔法(wit)心靈(sou)科技(tec)
   "damage_type":  "刺傷", 
]),
([
   "action": "$N提劍虛畫七劃，似北斗七星，層層包住$n，趁機抽劍一擊，一招"HIC"「"HIB"罡\"HIC"」"NOR"戳向$n的$l",
   "damage":       100+random(99),
   "dodge":        -5,
   "delay":        1,
   "attack_type":  "tec",
   "damage_type":  "刺傷",
]),
([
   "action": "$N隱身潛進，突然在$n身旁對$n出了一招"HIC"「"HIG"蔚"HIC"」"NOR,
   "damage":       100+random(99),
   "delay":        2,
   "attack_type":  "tec",
   "damage_type":  "刺傷",
]), 
([
   "action": "$N口中喃喃念道『背故都之沃衍，適新邑之丘墟』，手中之劍突然挑起土，使了"HIC"「"YEL"沃"HIC"」"NOR,
   "damage":       100+random(99),
   "delay":        2,
   "attack_type":  "tec",
   "damage_type":  "刺傷",
]),
([
   "action": "$N運氣於臂，手上的劍突然嗡嗡作響，氣勢驟升，對$n的$l使出一招"HIC"「"HIW"奘"HIC"」"NOR,
   "damage":       100+random(99),
   "attack_type":  "tec",
   "damage_type":  "刺傷",
]), 
([
   "action": "\n"HIM"奮力迎擊！近身貼戰，硬是接下了數道劍氣！\n"NOR, 
   "damage":       200+random(99),
   "delay":        2,
   "attack_type":  "tec",
   "damage_type":  "創傷",
]),
});

string *sor_str= ({
"$N隱身潛進，突然在$n身旁對$n出了一招"HIC"「"HIG"蔚"HIC"」"NOR,
"$N提劍虛畫七劃，似北斗七星，層層包住$n，趁機抽劍一擊，一招"HIC"「"HIB"罡\"HIC"」"NOR"戳向$n的$l",
"$N屈劍一指，內力潛進劍中，使出"HIC"「"HIR"煜"HIC"」"NOR"字訣，劍招狠狠的斗直直進",
"$N口中喃喃念道『背故都之沃衍，適新邑之丘墟』，手中之劍突然挑起土，使了"HIC"「"YEL"沃"HIC"」"NOR,
"$N運氣於臂，手上的劍突然嗡嗡作響，氣勢驟升，對$n的$l使出一招"HIC"「"HIW"奘"HIC"」"NOR,
"\n"HIM"奮力迎擊！近身貼戰，硬是接下了數道劍氣！\n",
});

int exert(object me, object target,string arg)
{
  string msg;
  int damage,sk,c,te,i; 
  object weapon,wp;  
  me=this_player();
  if(!me) return 0;
  if(!me->is_fighting()) return notify_fail(SKILL_NAME+"是一種戰鬥技能!\n");
  if( !target ) target = offensive_target(me);
  if( !target ) return notify_fail("你要對誰使出"+SKILL_NAME+"?\n");    
  if( me->query_temp("nan") )
    return notify_fail("你短時間內不能使用"+SKILL_NAME+"！\n");     
  if((int)me->query("mp") < 50 || (int)me->query("ap") < 100)
    return notify_fail("你目前的身體狀況無法使用這麼劇烈的武功\﹗\n");
  if(!weapon=me->query_temp("weapon")) return notify_fail("使用索星奧義需要使用武器。\n"); 
  if(weapon->query("skill_type")!="sword") 
    return notify_fail("使用"+SKILL_NAME+"必須要有劍。\n"); 
  if(me->query_skill("sword")<100) 
    return notify_fail("使用"+SKILL_NAME+"需要極為紮實的劍法基礎。\n"); 
  if(me->query_skill("dodge")<100)
    return notify_fail("使用"+SKILL_NAME+"需要極為紮實的閃躲基礎。\n");
  if(me->query_skill("sorgi_sword")<100)
    return notify_fail("使用"+SKILL_NAME+"需要極為紮實的索極劍法。\n");
  if(me->query_skill("star-sword")<100)
    return notify_fail("使用"+SKILL_NAME+"需要極為紮實的昂星劍義。\n");
  if(me->query_skill("moon_force")<100)
    return notify_fail("使用"+SKILL_NAME+"需要渾厚的殘月心法。\n");
  if(me->query_skill("force")<100)
    return notify_fail("使用"+SKILL_NAME+"需要渾厚的內功\。\n"); 
  if(me->query_dex() <60) 
    return notify_fail("使用"+SKILL_NAME+"需要足夠的敏捷。\n");
  sk=me->query_skill("sorsin_force"); 
  te=me->query_Merits("tec");
  c=target->query_armor();
  message_vision("\n"HIW"$N將內力貫注於手中之劍，充盈的"HIC"劍氣"HIW"蓄勢待發•••\n"NOR,me,target);
  me->receive_damage("mp",15+sk/5);
  me->receive_damage("ap",30+sk/3);
  if(arg != "one") return notify_fail("\n你要使出"+SKILL_NAME+"的什麼功\能？\n");
  if(me->query_skill("sorsin_force") >33) 
    return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
  if(me->query_dex()*2 < target->query_skill("dodge")+random(12))
  {
    msg += "\n"HIW""+target->name()+"先發制人！阻止了$N的出招。\n"NOR; 
    message_vision(msg,me,target);
    me->add_temp("nan",1);
    call_out("stop_delay",180/te,me);
  }
  else
  {
    damage = me->query_damage()*2+sk*2+me->query_dex()*2-c/2;
    //damage = COMBAT_D->Merits_damage(me,target,damage,"tec");             
    msg += "\n"HIM"奮力迎擊！左閃右擋，硬是接下了數道劍氣！[受到("+damage+")點的傷害]\n"NOR; 
    message_vision(msg,me,target);
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    target->start_busy(te/2); 
    me->start_busy(2); 
    me->add_temp("nan",1);
    call_out("stop_delay",180/te,me); 
    me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8)); 
  }

  if(arg != "two") return notify_fail("\n你要使出"+SKILL_NAME+"的什麼招式？\n"); 
  if(me->query_skill("sorsin_force") >66) 
    return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
  if(me->query_dex()*2 < target->query_skill("dodge")+random(12))
  {
    msg += HIW"\n"+target->name()+"先發制人！阻止了$N的出招。\n"NOR; 
    message_vision(msg,me,target);
    me->add_temp("nan",1);
    call_out("stop_delay",180/te,me);
  }
  else
  {
    damage = me->query_damage()*3+sk*7+me->query_dex()*4-c/3;
    //damage = COMBAT_D->Merits_damage(me,target,damage,"tec");    
    msg += "\n\t"HIG"劍風一起！\n"
    "\t\t"HIB"『"HIC"殘月之祕•幻滅疾念"HIB"』\n"
    "\t\t"HIW"一股劍氣掃蕩在"+target->name()+"的周圍！四面空氣滋滋作響！\n"
    "\t\t"HIC"天疾星陣"HIW"奪劍而出！百道劍氣••由陣導入••\n"
    "\t\t"HIR"鮮血哀嚎••"+target->name()+"可見••[("+damage+")點的傷害值]\n"NOR; 
    message_vision(msg,me,target);
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    target->start_busy(te/2); 
    me->start_busy(2); 
    me->add_temp("nan",1);
    call_out("stop_delay",240/te,me); 
    me->improve_skill("sorsin_force",2+random(me->query_dex()/8+me->query_Merits("tec")/4+sk/8));  
  } 

  if(arg != "three") return notify_fail("\n你要使出"+SKILL_NAME+"的什麼?\n"); 
  if(me->query_skill("sorsin_force") >99) 
    return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n"); 
  if(me->query_dex()*2 < target->query_skill("dodge")+random(12))
  {
    msg += "\n"HIW""+target->name()+"先發制人！抑止了$N的招式。\n"NOR; 
    message_vision(msg,me,target);
    me->add_temp("nan",1);
    call_out("stop_delay",180/te,me);
  }
  else
  {
    damage = me->query_damage()*5+sk*10+me->query_dex()*5-c/2;
    //damage = COMBAT_D->Merits_damage(me,target,damage,"tec");   
    msg += "\n\t"HIG"劍風一起！"HIR"$N的眼神被血紅所覆蓋\！\n"
    "\t\t"HIB"『"HIC"殘月之祕•幻滅疾念"HIW"•瞬•天•殺"HIB"』\n"  
    "\t\t"HIW"一股劍氣掃蕩在"+target->name()+"的周圍！四面空氣滋滋作響！\n"
    "\t\t"HIW"竟導出了雙重"HIC"天疾星陣"HIW"！千道劍氣！"HIR"殺無赦！\n"
    "\t\t""HIR"+target->name()+"卻在"HIW"白光"HIR"閃完之後，已倒在血泊當中••[("+damage+"點的傷害值)]\n"NOR; 
    message_vision(msg,me,target);
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    target->start_busy(te/2);
    me->start_busy(2);
    me->add_temp("nan",1);
    call_out("stop_delay",360/te,me);
    me->improve_skill("sorsin_force",10+random(me->query_dex()/2+me->query_Merits("tec")*2+sk/2)); 
  }
         
  if(arg != "final") return notify_fail("\n你要使出"+SKILL_NAME+"的什麼?\n");
  if(me->query_skill("sorsin_force") >99)
    return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n"); 
  if(me->query_dex()*2 < target->query_skill("dodge")+random(12))
  {
    msg += "\n"HIW""+target->name()+"先發制人！抑止了$N的招式。\n"NOR;
    message_vision(msg,me,target);
    me->add_temp("nan",1);
    call_out("stop_delay",540/te,me); 
  }
  else
  {
    damage = me->query_damage()*10+sk*10+me->query_dex()+10-c/2;
    //damage = COMBAT_D->Merits_damage(me,target,damage,"tec");                
    message_vision("\n"HIC"$N一股作氣！將內勁一次導入劍內，使出疾風連技『"HIW"索星天壁"HIC"』\n"NOR,me,target);
    for(i=0;sizeof(sor_str);i++)
    {
      msg=sor_str[random(sizeof(sor_str))];
      message_vision(msg,me,target);
    }
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    target->start_busy(te/2);
    me->start_busy(2);
    me->add_temp("nan",1);
    call_out("stop_delay",360/te,me);
    me->improve_skill("sorsin_force",10+random(me->query_dex()/2+me->query_Merits("tec")*2+sk/2));
  }          
  return 1;
}
                 
void stop_delay(object me)
{
  if( !me ) return;
  me->delete_temp("nan");
}

int improve_limite(object ob)
{
  return 100;
}
