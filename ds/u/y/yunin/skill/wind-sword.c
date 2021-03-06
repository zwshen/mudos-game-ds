#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void superpower(object me);
mapping *action = ({

          ([  
        "action": "$N你一式「清風襲月」，劍鋒平指，劍勢如風，一氣呵成猛攻$n的的頸部！！", 
        "damage":                12,
        "dodge" :                12,
        "parry" :                18,
        "attact_type":  "bio",  
        "damage_type":  "劍傷",
        ]),
        ([
        "action": "你向前躍上一步，左手劍訣，右手鋼劍使出一式「飄雪穿雲」直刺$n的後心！ ",
        "damage":                15,
        "dodge" :                 5,
        "parry" :                25,
        "attact_type":  "bio",  
        "damage_type":  "穿傷",
        ]),
        ([
        "action": "$n你劍斜指蒼天，一式「千峰競秀」，化出無數個劍尖，裹向$n的左腳！ ",
        "damage":                20,
        "dodge" :                10,
        "parry" :                20,
        "attact_type":  "bio",  
        "damage_type":  "無數劍傷",
        ]),
        ([
        "action": "$N你一式「萬流歸宗」，鋼劍自上而下緩緩劃出一個大弧，突然從中向$n刺出！", 
        "damage":                18,
        "dodge" :                17,
        "parry" :                13,
        "attact_type":  "bio",  
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$身擰腰，一式「烏龍攪柱」，鋼劍隨身平劃，點向$n的胸腹要穴！ ",
        "damage":                10,
        "dodge" :                15,
        "parry" :                15,
        "attact_type":  "bio",  
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N一式「大雁啼沙」，全身貼地平飛，身劍合一，閃電般刺向$n的左腿！ ",
        "damage":                15,
        "dodge" :                10,
        "parry" :                20,
        "attact_type":  "bio",  
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N施出「進退龍遊」，鋼劍脫手飛出，如遊龍般翱翔青宇，破空射向$n的胸口！", 
        "damage":                12,
        "dodge" :                20,
        "parry" :                10,
        "attact_type":  "bio",  
        "damage_type":  "穿傷",
        ]),

        ([
        "action": "$N長嘯一聲，一式「天地鶴翔」，騰空飛起，全身迸出無數道雪亮劍芒，照耀天際！ ",
        "damage":                12,
        "dodge" :                20,
        "parry" :                10,
        "attact_type":  "bio",  
        "damage_type":  "劍傷",
        ]),
});
mapping *s_action = ({
        ([
        "action": 
          HIR"$N手中長劍劍芒躍動﹐劍光暴長﹐幻出死亡的色彩﹐劍尖漸影化為一劍直刺木人前胸﹐快捷無倫﹐只有一劍﹗ 
   木人根本沒法躲避﹐一式「迴風拂柳劍」的絕招"HIY"「"HIB"滅劍"HIY"」"HIR"端端正正插進在$n胸口﹗木人一低頭﹐看長劍自胸口拔出﹗",NOR   

        "damage":                80,
        "dodge" :                30,
        "parry" :                30,
        "hit" :                  45,
        "attact_type":  "bio",  
        "damage_type":  "劍傷",
        ]),
});

int exert(object me, object target, string arg)
{
        string msg;
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("sword")!="wind-sword")
                        return notify_fail("你沒施展回風拂柳劍 !!\n");
                me->map_skill("sword");
                me->reset_action();
                write("你不在使用回風拂柳劍 !!\n");
                return 1;
        }
    if ( !weapon )  return notify_fail("手中要有劍才能使出回風拂柳劍 。\n");
          if( weapon->query("skill_type")!="sword")
                return notify_fail("手中要有劍才能使出回風拂柳劍 。\n");

        if(me->query_skill_mapped("sword")=="wind-sword") 
                return notify_fail("你正在施展回風拂柳劍 了。\n");
        if(me->query("ap")<15 || me->query("hp")<15 )
                 return notify_fail("你的身體狀況無法使用回風拂柳劍 。\n");
        me->map_skill("sword", "wind-sword");
        me->reset_action();
        message_vision(HIR"$N正氣一喝"+weapon->query("name")+HIR"便開始使出回風拂柳劍 。\n"NOR,me);
        me->receive_damage("ap",5);
        me->start_busy(1);
 
        return 1;
}
mapping query_action(object me, object weapon)
{
    if (me->query_temp("wind-sword/five-hit") ) return action[random(sizeof(action))];
    if ( me->query_skill("wind-sword") >=90 && me->query("ap") > 150 && random(200)>=190 )
    {
        me->start_busy(2);
        me->skill_active( "wind-sword",(: call_other, __FILE__, "five-hit",me:), 3);
    }
    if ( me->query_skill("wind-sword") >= 51  && me->query("ap") > 51 && random(200)>=171 )
    {
        me->receive_damage("ap",10);
        me->start_busy(1);
        return s_action[0];
    }
    return action[random(sizeof(action))];
}

void superpower(object me)
{
     int i,damage;
     object target,weapon;
     string *limbs;
     weapon=me->query_temp("weapon");

     if( !target ) target = offensive_target(me);

    if( environment(me) != environment(target) ) return;
     if(!me->is_fighting()) return;

message_vision(HIG"$N大喝一聲，使出回柳裕劍五擊，手中"+weapon->query("name")+HIG"場面顯出了閃閃的光茫。\n"NOR,me);
     for (i=0;i<=4;i++)
     {
       damage=30+random(20);
       limbs = target->query("limbs");
       message_vision(HIW"$N將手中"+weapon->query("name")+"實緊，劍氣刺向$n的"+limbs[random(sizeof(limbs))]+"。"NOR,me,target);
           switch( random(20) ) {
           case 0:
               message_vision(HIW"$n輕鬆一躍，躲開了攻擊!!。\n"NOR,me,target);
               break;
           case 1:
               message_vision(HIW"$n不懼你的攻擊，檔了下來\n"NOR,me,target);
               break;
           case 2:
               message_vision(HIW"$n輕鬆一閃，避開了攻擊。\n"NOR,me,target);
               break;
           case 3:
               message_vision(HIW"$n輕鬆一躲，閃開了攻擊。\n"NOR,me,target);
               break;
           default:
               message_vision("$n被劍氣刺中，當場噴血！！",me,target);
               target->receive_damage("hp",damage);
             if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                     tell_object(me,HIY"("+damage+")"NOR"\n");
             COMBAT_D->report_status(target);         //顯示target狀態
             if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                     tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp") +")");
            if(wizardp(me) && me->query("env/debug")) 
                     tell_object(me,"  造成"+damage+"點傷害!!\n"); 
               me->receive_damage("ap",15+random(6));
               break;
           }
     }
     me->delete_temp("wind-sword/five-hit");
}

int practice_skill(object me) { return 1; }
int valid_learn(object me)    { return 1; }


