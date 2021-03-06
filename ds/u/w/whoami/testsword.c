/*
 Sorsin_Force V2.0             DATE:2006/04/07      
                                       
 總共有 one two three final 四招
 one -> 沒啥用的廢招, 拿來練skill而已 
 two -> 命中率極低的招式, 一但命中, 劍氣將對敵人產生無可想像的威力
 three -> 攻擊全體敵人的招式, 有點像penuma-sword的進階版本
 final -> 連擊招式, 最高上限為25下, 傷害力跟 bar 相關                        
 
 ※該技能定住敵人的時間和自身 tec 有關, 除了 final 傷害力皆和 bio^2 成正比 

 Edit By Whoami@DS 
      P.S. 特此感謝 watermoon , godfire , manto 等人提供招示敘述.. 
*/  
 
   



//【好友】水雲齋(Watermoon)﹕一時間你感到體內氣血有如萬馬奔騰,疼痛難耐,一口鮮血就這麼從口中嘔了出來

//只見$n眉頭一皺，劍氣突破內力屏障攻向身體要穴
//成功: $n反應不及，口噴鮮血
//失敗: $n伸指點穴，抑制了劍氣流竄

//沒有發出一點聲音，sorsin劍氣順著經脈散佈全身，ooxx渾身一顫，全身的真氣瞬間被逼的一亂，張著嘴，有一口沒一口的吐著鮮血
//全身的真氣瞬間被逼的一亂，竟然不受自己的管制，渾身上下亂竄起來，ooxx張口吐出一口鮮血，臉色瞬間變得慘白。


//#include <ansi.h>
#define SKILL_NAME "索星奧義"
//inherit SKILL;
#include <ansi.h>
#include <weapon.h>

inherit SSERVER; 
inherit SWORD;

void stop_delay(object me);

string *sor_str= ({
"$N隱身潛進，突然在$n身旁對$n出了一招"HIC"「"HIG"蔚"HIC"」\n"NOR,
"$N提劍虛畫七劃，似北斗七星，層層包住$n，趁機抽劍一擊，一招"HIC"「"HIB"罡\"HIC"」\n"NOR,
"$N屈劍一指，內力潛進劍中，使出"HIC"「"HIR"煜"HIC"」"NOR"字訣，劍招狠狠的斗直直進\n",
"$N口中喃喃念道『背故都之沃衍，適新邑之丘墟』，手中之劍突然挑起土，使了"HIC"「"YEL"沃"HIC"」\n"NOR,
"$N運氣於臂，手上的劍突然嗡嗡作響，氣勢驟升，對$n使出一招"HIC"「"HIW"奘"HIC"」\n"NOR,
});

void create()
{
set_name("陰陽長劍",({"yin-yang longsword","sword","longsword"})); 
set("long","這是一把由獨臂老人所打造出來的最佳傑作，但是現在劍身卻顯得\n"
           "暗淡無光•\n");
set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("limit_str",30); 
        set("limit_int",30);
        set("limit_dex",50); 
        set("limit_level",45);
        set("value",10000);
        set("material","blacksteel");
        }
        init_sword(45);
        setup(); 
}

void init()
{
     add_action("do_exert","nexert");
}

int do_exert(string arg, object me, object target)
{
  string msg="";
  int damage,sk,c,te,i,x,y,delay_time,busy_time; 
  object weapon,*inv;

  me=this_player();
  inv = all_inventory(environment(me));
  
  if(!me) return 0;
  if(!me->is_fighting()) return notify_fail(SKILL_NAME+"是一種戰鬥技能!\n");
  if( me->is_busy()) return notify_fail("你現在沒空！\n");
  if( !target ) target = offensive_target(me);
  if( !target ) return notify_fail("你要對誰使出"+SKILL_NAME+"?\n");    
  if( me->query_temp("nan") )
    return notify_fail("你短時間內不能使用"+SKILL_NAME+"！\n");     
  if((int)me->query("mp") < 100 || (int)me->query("ap") < 100)
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
  if(me->query_dex() < 60) 
    return notify_fail("使用"+SKILL_NAME+"需要足夠的敏捷。\n"); 
  if(me->query_Merits("tec") < 1)
    return notify_fail("使用"+SKILL_NAME+"，科技(TEC)不能等於零。\n"); 

  sk=me->query_skill("sorsin_force"); 
  te=me->query_Merits("tec");
  c=target->query_armor();
  weapon=me->query_temp("weapon");
  
  me->receive_damage("mp",(random(sk)/2)+10);
  me->receive_damage("ap",(random(sk)/2+sk/2)+10);   
  me->add_temp("nan",1);
  
  
  msg += "\n"HIW"$N";
  if( me->query("evil") ){
      msg += HIW+BLK"陰陰的笑了一下"HIW;
      } else {
      msg += HIW"淺淺的笑了一下";
      } 
  msg += "，手中的"+weapon->query("name")+"忽然展開了一束"HIM"彩虹"HIW"般的艷光，如羽翼般鋪天蓋\地地罩向$n。\n"NOR;     

  switch ( arg ){
         case "one":
              if(me->query_skill("sorsin_force") < 1)
                return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
              if( random(me->query("dex")*4) > random(target->query_skill("dodge")*2) || target->is_busy() ){

                damage = me->query_damage()-random(c);
                damage = damage * (random(3)+1);                                      
                if( damage < 0 ) damage = 0;
                
                busy_time = random(1); //npc delay的回合數 
                delay_time = 2+random(2);   //自己 delay 的回合數 
              
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
                me->start_busy(2);
                call_out("stop_delay",40/te,me);    // 40 / tec 約略 5秒 能出下一招    
              } 
                       
         break;
         case "two":  
              if(me->query_skill("sorsin_force") < 60) // 改成60 by whoami 
                return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
              if( random(me->query("dex")*5) > random(target->query_skill("dodge")*3) || target->is_busy() ){
                  damage = me->query_damage()-random(c);
                  if( damage < 0 ) damage = 0;
                
                busy_time = random(te/4); //npc delay的回合數 
                delay_time = random(sk/20)+1;   //自己 delay 的回合數 
                
                msg += "\n$N凝氣御劍，蹤躍凌空，劍氣自劍尖散射而出！\n"NOR;  
                msg += "\n\t倏忽間一道"HIW"冷冽的劍氣"NOR"疾射而出，以令人咋舌的速度硬生生的直射$n！！\n"NOR; 


                if( random(me->query_bio())+(sk/50) > random(target->query_bio()) ){                
                   msg += "\n只見劍氣虛虛實實，避無可避。轉瞬間劍氣灌入$n體內，$n慘聲哀嚎！\n"; 
                   tell_object(target ,CYN"\t(在你的體內似乎多了一股不穩定的氣息。)\n");
//                   target->apply_condition("sorsin_force", 
//                   target->query_condition("sorsin_force")+random((me->query_skill("sorsin_force")/20)-1));
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
                  
                call_out("stop_delay",60/te,me); // 60 / tec 約略 8秒 能出下一招 
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"先發制人！阻止了$N的出招。\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(2);
                call_out("stop_delay",40/te,me);    // 40 / tec 約略 5秒 能出下一招    
              } 
         break;
         case "three":
              if(me->query_skill("sorsin_force") < 80) // 改成80 by whoami 
                return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
              if( random(me->query("dex")*6) > random(target->query_skill("dodge")*4) || target->is_busy() ){
      
                
                busy_time = random(me->query_skill("sorsin_force")/30); //npc delay的回合數 


                msg += "\n$N開始了那優美而恐怖的死亡之舞。劍芒化為滿"HIC"天青色的閃電，\n"NOR
                       "\n                宛如"HIY"落日之光"NOR"，一瞬間籠罩了在場的每一個人…\n";
                msg += "\n$N的劍光如"HIY"急雨"NOR"、如"HIM"落花"NOR"、如"HIC"飛瀑"NOR"、如"HIG"激流"NOR"，"HIY"劍花錯落"NOR"，"HIY"神光流盼"NOR"，將";

                for( i=0;i<sizeof(inv);i++ ){
                     if( !inv[i]->is_fighting(me) ) continue;
                     me->add_temp("sorsin_ppl_account",1);
                     inv[i]->add_temp("sorsin_target",1);
                     delay_time = i;   //自己 delay 的回合數 
                    }
                    
                for( i=0;i<sizeof(inv);i++ ){
                     if( !inv[i]->query_temp("sorsin_target") ) continue;
                     msg += ""+inv[i]->query("name")+"";
                     if( me->query_temp("sorsin_ppl_account") > 1 ){
                     msg += "、"; 
                     me->add_temp("sorsin_ppl_account",-1);
                     }
                    }
                for( i=0;i<sizeof(inv);i++ )
                     inv[i] -> delete_temp("sorsin_target"); 

                msg += "的週身要害團團籠罩……\n"NOR;

                message_vision(msg,me,target);
                
                for( i=0;i<sizeof(inv);i++ ){ 
                     if( !inv[i]->is_fighting(me) ) continue; 

                x = random(me->query_skill("sorsin_force")/30)+te/4;
                if( x > 5 ) x = 5;         
                       
                     damage = me->query_damage()-random(c);
                     damage = damage + (me->query_bio()*me->query_bio()*(random(me->query_dex()/10)) );
                     damage = damage*x;
                     
                     if( damage < 0 ) damage = 0;
                     if( random(me->query("dex")*6) > random(inv[i]->query_skill("dodge")*4) || inv[i]->is_busy() ){
                     message_vision("\n$N身形如電，劍招一招接著一招遞出，"+inv[i]->query("name")+"反應不及，身中"+chinese_number(x)+"劍！\n",me); 
                     if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                        tell_object(me,HIY"("+damage+")\n"NOR);
                     if(inv[i]->query_temp("apply/show_damage") || inv[i]->query_temp("show_damage") )
                        tell_object(inv[i],HIR"("+damage+")"NOR+" ("+inv[i]->query("hp")+"/"+inv[i]->query("max_hp")+")");
                      inv[i]->receive_damage("hp",damage,me); 
                      COMBAT_D->report_status(inv[i]); 
                      inv[i]->start_busy(busy_time); 

                     } else {
                     message_vision("\n的身子一個輕盈的飛旋，險過毫釐地閃開了這記凌利劍招！\n",me,inv[i]);
                     }       
                }       
                me->start_busy(delay_time);
          
                me->delete_temp("sorsin_ppl_account");                      
                call_out("stop_delay",100/te,me);   // 100 / tec 約略 12秒 能出下一招   
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"先發制人！阻止了$N的出招。\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(2);
                call_out("stop_delay",40/te,me);    // 40 / tec 約略 5秒 能出下一招    
              } 
         break;
         case "final":
              if(me->query_skill("sorsin_force") < 99)  
                return notify_fail("\n你的"+SKILL_NAME+"還沒到那境界。\n");  
              if( random(me->query("dex")*7) > random(target->query_skill("dodge")*5) || target->is_busy() ){

                x = me->query_skill("sorsin_force")/5+te/4;
                if( x > 25 ) x = 25;

                damage = me->query_damage()-random(c);
                damage = (damage*me->query_bio()*me->query_bio())/5;
//                damage = damage - (target->query_skill("force"))*(target->query("Merits/bio")/2);
                damage = damage + random(me->query_dex()/10)*x;
                if( damage < 0 ) damage = 0;
                   
                busy_time = random(te)/2; //npc delay的回合數 
                if( busy_time < 1 ) busy_time = 0;
                delay_time = x/te;   //自己 delay 的回合數 

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
                  
                call_out("stop_delay",120/te,me);  // 120 / tec 約略 15秒 能出下一招   
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"先發制人！阻止了$N的出招。\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(2);
                call_out("stop_delay",40/te,me);    // 40 / tec 約略 5秒 能出下一招    
              } 
         break;
         default:
              tell_object(me,HIC"\n"+SKILL_NAME+"目前有 one two three final 四項功\能，詳見 help sorsin_force。\n"NOR);        
         break;
  }
  return 1;                            
}  

void stop_delay(object me)
{
 if(!me) return;
 me->delete_temp("nan");
}

int improve_limite(object ob)
{
 return 100;
}
