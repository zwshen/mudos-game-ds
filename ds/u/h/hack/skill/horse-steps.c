// QC: Luky 1999.10.16 14:39
//update -By tmr-  2000/3/4

#include <ansi.h>

inherit SKILL;

void delay(object me,int cost);

int exert(object me, object target, string arg)
{
        int sk,power,hpower,bagi_power;
        string sp;
        sk=me->query_skill("horse-steps");
                bagi_power=me->query_temp("exert_mark/bagi-power"); //減少 query 運算,並易於修改
               
                switch(arg)
                {
        //沉墜勁
                case "down-power":
                if(sk<30) 
                        return notify_fail("你的紮馬基礎不夠，無法凝聚沉墜勁。\n");
                if(me->query("ap") < 15 )
                        return notify_fail("你的內勁不夠凝聚沉墜勁。\n");
                if(bagi_power >= sk ) 
                        return notify_fail("你體內的八極氣勁已沛然滿溢了。\n");
                        power=5;
                        me->receive_damage("ap",5);
                sp=HIW"$N馬步一坐，將全身勁道筆直下沉地分佈身體各部位。\n" NOR;
     me->start_busy(2);
                break;
        //十字勁
                case "ten-power":
                if(sk<60) 
                        return notify_fail("你的紮馬基礎不夠，無法凝聚十字勁。\n");
                if(me->query("ap") < 30 )
                        return notify_fail("你的內勁不夠凝聚十字勁。\n");
                if(bagi_power >= sk ) 
                        return notify_fail("你體內的八極氣勁已沛然滿溢了。\n");
                          power=15;
                        me->receive_damage("ap",10);
            sp=HIW"$N將全身勁道向上、下、左、右四個方向畫十字運作。\n" NOR;
           me->start_busy(2);
                break;
        //纏絲勁
                case "twine-power":
                if(sk<95) 
                        return notify_fail("你的紮馬基礎不夠，無法凝聚纏絲勁。\n");
                if(me->query("ap") < 50 )
                          return notify_fail("你的內勁不夠凝聚纏絲勁。\n");
                if(bagi_power >= sk ) 
                        return notify_fail("你體內的八極氣勁已沛然滿溢了。\n");
                        power=30;
                        me->receive_damage("ap",15);
                sp=HIW"$N將全身的氣勁旋轉、穿扭般在體內循環不息。\n" NOR;
           me->start_busy(2);
                break;
        case "power":
                if(bagi_power < 10) sp="你覺得體內空蕩蕩的，一點勁道也沒有。";
                else if(bagi_power < 20) sp="你評估體內的八極勁道約在十至百來之數。";
                else if(bagi_power < 30) sp="你評估體內的八極勁道約在二百來之數。";
                else if(bagi_power < 40) sp="你評估體內的八極勁道約在三百來之數。";
                else if(bagi_power < 50) sp="你評估體內的八極勁道約在四百來之數。";
                else if(bagi_power < 60) sp="你評估體內的八極勁道約在五百來之數。";
                else if(bagi_power < 70) sp="你評估體內的八極勁道約在六百來之數。";
                else if(bagi_power < 80) sp="你評估體內的八極勁道約在七百來之數。";
                else if(bagi_power < 90) sp="你評估體內的八極勁道約在八百來之數。";
                else if(bagi_power < 98) sp="你評估體內的八極勁道約在九百來之數。";
                else sp="你覺得體內氣勁充沛奔騰，難以控制。";
                write(sp+"\n");
                return 1;
                default:
                        return notify_fail("目前有down-power,ten-power,twine-power,power 等功\能\n");
                }
                hpower=power;
                message_vision(sp,me);
                me->add_temp("exert_mark/bagi-power",hpower);
                return 1;
}

int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }


