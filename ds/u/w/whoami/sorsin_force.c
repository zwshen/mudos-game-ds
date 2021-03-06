/*****************************************************/
/* Sorsin_Force V2.0             DATE:2006.4.03      */
/* EDITOR:Whoami                                     */ 
/* 新增 two 將對敵人砍入劍氣                         */ 
/*****************************************************/

//【好友】水雲齋(Watermoon)﹕一時間你感到體內氣血有如萬馬奔騰,疼痛難耐,一口鮮血就這麼從口中嘔了出來

#include <ansi.h>
#define SKILL_NAME "索星奧義"
inherit SKILL;
inherit SSERVER; 

string *sor_str= ({
"$N隱身潛進，突然在$n身旁對$n出了一招"HIC"「"HIG"蔚"HIC"」\n"NOR,
"$N提劍虛畫七劃，似北斗七星，層層包住$n，趁機抽劍一擊，一招"HIC"「"HIB"罡\"HIC"」\n"NOR,
"$N屈劍一指，內力潛進劍中，使出"HIC"「"HIR"煜"HIC"」"NOR"字訣，劍招狠狠的斗直直進\n",
"$N口中喃喃念道『背故都之沃衍，適新邑之丘墟』，手中之劍突然挑起土，使了"HIC"「"YEL"沃"HIC"」\n"NOR,
"$N運氣於臂，手上的劍突然嗡嗡作響，氣勢驟升，對$n使出一招"HIC"「"HIW"奘"HIC"」\n"NOR,
});

int exert(object me, object target,string arg)
{
  string msg="";
  int damage,sk,c,te,i,x,delay_time,busy_time,wp; 
  object weapon,*inv;

  me=this_player();
  te=me->query_Merits("tec");
  c=target->query_armor();
  me->receive_damage("mp",random(sk));
  me->receive_damage("ap",random(sk)+sk);   
weapon=me->query_temp("weapon");
  me->add_temp("nan",1); 
  inv = all_inventory(environment(me));
  
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
  if(me->query_Merits("tec") <1)
    return notify_fail("使用"+SKILL_NAME+"，科技(TEC)不能等於零。\n"); 
  sk=me->query_skill("sorsin_force"); 
  
  msg += "\n"HIW"$N向前猛然踏了一大步，左足深陷在硬土地中，"+weapon->query("name")+"筆直地指向前方不遠處站立的$n，劍光清冽如碧淵泉水，流光溢彩。\n"NOR;

  switch ( arg ){
         case "one":
              if(me->query_skill("sorsin_force") < 1)
                return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
              if( random(me->query("dex")*4) > random(target->query_skill("dodge")*2) || target->is_busy() ){
                damage = me->query_damage()-random(c);
                damage = damage * (random(3)+1);                                      
                if( damage < 0 ) damage = 0;
                
                busy_time = random(me->query_skill("sorsin_force")/30); //npc delay的回合數 
                delay_time = 20/(me->query_skill("sorsin_force")/20);   //自己 delay 的回合數 
              
                msg += "\n"HIM""+target->name()+"奮力迎擊！左閃右擋，硬是接下了數道劍氣！\n"NOR;  

                message_vision(msg,me,target);

                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                  tell_object(me,HIY"("+damage+")\n"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                  tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");

                target->receive_damage("hp",damage,me); 
                COMBAT_D->report_status(target); 
 
                target->start_busy(busy_time); 
                me->start_busy(delay_time);  
                call_out("stop_delay",20/te,me); 
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"先發制人！阻止了$N的出招。\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(1);
                call_out("stop_delay",40/te,me);    // 40 / tec 約略 4秒 能出下一招    
              } 
                       
         break;
         case "two":
              if(me->query_skill("sorsin_force") < 50) // 改成50 by whoami 
                return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
              if( random(me->query("dex")*5) > random(target->query_skill("dodge")*3) || target->is_busy() ){
                  damage = me->query_damage()-random(c);
                  if( damage < 0 ) damage = 0;
                
                busy_time = random(me->query_skill("sorsin_force")/30); //npc delay的回合數 
                delay_time = 20/(me->query_skill("sorsin_force")/20);   //自己 delay 的回合數 
                
                msg += "\n"HIM"$N凝氣御劍，蹤躍凌空，劍氣自劍尖散射而出！\n"NOR;  
                msg += "\n倏忽間一道冷冽的劍氣疾射而出，以令人咋舌的速度硬生生的直射$n！！\n"NOR; 


                if( random(me->query("Merits/bio"))+sk/50 > random(target->query("Meris/bio")) ){                
                   msg += "\n只見劍氣虛虛實實，避無可避，轉瞬間劍氣灌入$n體內，$n慘聲哀嚎！\n"; 
                   damage = damage*2;
                   } else {
                   msg += "只見$N一時氣血奔騰，心神繁亂，劍氣頓時失去了準度，僅僅擦過$n身邊。\n"; 
                   }

                message_vision(msg,me,target);
                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                  tell_object(me,HIY"("+damage+")\n"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                  tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");

                target->receive_damage("hp",damage,me); 
                COMBAT_D->report_status(target); 
 
                target->start_busy(busy_time); 
                me->start_busy(delay_time);  
                call_out("stop_delay",40/te,me); 
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"先發制人！阻止了$N的出招。\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(1);
                call_out("stop_delay",40/te,me);    // 40 / tec 約略 4秒 能出下一招    
              } 
         break;
         case "three":
              if(me->query_skill("sorsin_force") < 80) // 改成80 by whoami 
                return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
              if( random(me->query("dex")*6) > random(target->query_skill("dodge")*4) || target->is_busy() ){

                damage = me->query_damage()-random(c);
                damage = damage + (me->query_dex()/2)*random(x);
                if( damage < 0 ) damage = 0;
                
                busy_time = random(me->query_skill("sorsin_force")/30); //npc delay的回合數 
                delay_time = 20/(me->query_skill("sorsin_force")/20);   //自己 delay 的回合數 

                msg += "\n$N開始了那優美而恐怖的死亡之舞。劍芒化為滿天青色的閃電，宛如落日的光芒，一瞬間籠罩了在場的每一個人…\n";
                msg += "\n$N的劍光如急雨、如落花、如飛瀑、如激流，劍花錯落，神光流盼，將";
                
                for( i=0;i<sizeof(inv);i++ ){
                     if( !inv[i]->is_fighting(me) ) continue;
                     msg += ""+inv[i]->query("name")+"";
                     if( i > 1 ) msg+= "、";
                     }
                msg += "的週身要害團團籠罩……\n"NOR;

                message_vision(msg,me,target);

                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                  tell_object(me,HIY"("+damage+")\n"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                  tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");

                target->receive_damage("hp",damage,me); 
                COMBAT_D->report_status(target); 
 
                target->start_busy(busy_time); 
                me->start_busy(delay_time);
                
            //    me->receive_damage("ap",x*40,me);
            //    me->receive_damage("mp",x*15,me);    
                  
                call_out("stop_delay",80/te,me); 
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"先發制人！阻止了$N的出招。\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(1);
                call_out("stop_delay",40/te,me);    // 40 / tec 約略 4秒 能出下一招    
              } 
         break;
         case "final":
              if(me->query_skill("sorsin_force") < 99) // 改成80 by whoami 
                return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
              if( random(me->query("dex")*7) > random(target->query_skill("dodge")*5) || target->is_busy() ){
                damage = me->query_damage()*5-random(c);
                damage = damage + me->query_dex()*random(10);
                damage = damage - (target->query_skill("force"))*(target->query("Merits/bio")/4);
                if( damage < 0 ) damage = 0;
            
                x = me->query_skill("sorsin_force")/5+te/4;
                if( x > 25 ) x = 25;
                    
                busy_time = random(me->query_skill("sorsin_force")/30); //npc delay的回合數 
                delay_time = 20/(me->query_skill("sorsin_force")/20);   //自己 delay 的回合數 

                message_vision("\n\t"HIW"$N一股作氣！將"HIB"內勁"HIW"一次導入劍內，使出疾風連技『"HIC"索星天壁"HIW"』\n\n"NOR,me,target);
                for(i=0;i<x;i++)
                {
                 msg=sor_str[random(sizeof(sor_str))];
                 message_vision(msg,me,target);
                }
                target->receive_damage("hp",damage,me); 

                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                  tell_object(me,HIY"("+damage+")\n"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                  tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");

                COMBAT_D->report_status(target); 
 
                target->start_busy(busy_time); 
                me->start_busy(delay_time);
                  
                call_out("stop_delay",80/te,me); 
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"先發制人！阻止了$N的出招。\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(1);
                call_out("stop_delay",40/te,me);    // 40 / tec 約略 4秒 能出下一招    
              } 
         break;
         default:
         break;
  }                            
}  
