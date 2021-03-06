//邪極宗 輕功 踏雪無痕 (unscar-steps)

#include <ansi.h>
inherit SKILL;
inherit SSERVER;


string *dodge_msg = ({
        "$n一式"GRN"「斜燕歸林去」"NOR"，身體如雨燕投林般直滑出丈餘。\n",
        "$n一式"MAG"「花蝶戲蕊心」"NOR"，忽然一彎腰，全身凌空而行，頓時閃過了$N的凌厲攻勢。\n",
        "$n一式"HIY"「黃雀啄葉露」"NOR"，足不動，手不抬，一轉眼間便繞到了$N的身後。\n",
        "$n一式"GRN"「青蜂弄花粉」"NOR"，一轉身間，四面八方飄動著無數個$n的身影，令$N手足無措。\n",
        "$n一式"HIW"「蜓尾點水舞」"NOR"，長袖一拂，全身化為一道白影，幽幽地從$N頭頂飄落。\n",
        "$n一式"MAG"「知了藏影蹤」"NOR"，身形倏的從$N的眼前飄過，長髮一甩，瀟灑之極。\n"
});

int exert(object me, object target, string arg)
{

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="unscar-steps")
            return notify_fail("你並沒有使用【踏雪無痕】。\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N慢慢的停下了腳步。\n"NOR,me);
        write("技能【踏雪無痕】已取消。\n");
        return 1;
    }

    if(me->query_skill("dodge")<20) return notify_fail("你的輕功\基礎不夠無法使用【踏雪無痕】。\n");
    if(me->query_skill_mapped("dodge")=="unscar-steps")
        return notify_fail("你已經在使用【踏雪無痕】。\n");
    if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("你目前的身體狀況無法使用【踏雪無痕】。\n");

if(!me->skill_active( "unscar-steps",(: call_other, __FILE__, "delay", me :), 10))
        return notify_fail("你的踏雪無痕收招動作還沒完成。\n");

    me->map_skill("dodge", "unscar-steps");
    me->reset_action();

    message_vision(HIW "$N長袖一拂，全身化為一道白影，開始施展【踏雪無痕】。\n"NOR,me);
    me->receive_damage("ap",2);
    me->start_busy(1);
    return 1;
}

void delay(object me)
{
    if(!me) return;

    if(me->query_skill_mapped("dodge")!="unscar-steps")
    {
        //remove_call_out("delay");
        return;
    }

    if(me->query("ap")<2)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N慢慢的停下了腳步。\n"NOR,me);
        tell_object(me,"你的體力不足無法繼續使用【踏雪無痕】。\n");
        //remove_call_out("delay");
        return ;
    }
    if(me->is_fighting()) me->receive_damage("ap",2);
me->skill_active( "unscar-steps",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }

void perform_dodge_attack(object me)
{
    int sk, i;
    object *targets;

    if(!me) return;
    targets = me->query_enemy();
    sk = me->query_skill("unscar-steps");
    if( sk >= 50 
        && me->query("ap") > 50 
         &&  (sk/10) - 4 > random(100) ) {       // 最高 10% 的發動機率
                me->receive_damage("ap", 25);
                message_vision(HIC"\n天魔功\在剎那間提升至極限，以$N"HIC"為中心的方圓一丈之內，像忽然凹陷下去成了一個無底深潭。\n"NOR, me);
                for(i=0;i<sizeof(targets);i++) {
                        if( !environment(me) ) continue;
                        if( !targets[i] || !environment(targets[i]) ) continue;
                        if(environment(me) != environment(targets[i]) ) continue;
                        if( targets[i]->is_busy()) continue;
                        message_vision(CYN"$n"CYN"覺得身邊的空間便如同塌陷一般，無力可發。\n"NOR,me, targets[i]);
                        targets[i]->start_busy(1);
                }
        }
}

string query_dodge_msg(string limb)
{
    perform_dodge_attack( offensive_target(this_player()));
    return dodge_msg[random(sizeof(dodge_msg))];
}


int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
    return 70 + ob->query_dex();
}
