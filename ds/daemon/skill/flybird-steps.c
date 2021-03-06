// 鳥渡術 flybird-steps
// Tmr 2006/11/22

#include <ansi.h>
#define SKILL_NAME "flybird-steps"
inherit SKILL;

string *dodge_msg = ({
        "\n$n足尖在地面一點，身形拔地而起，"HIC"「飛靈八方」"NOR"躲開了這一招。\n",
        "\n$n隨著$N攻來的招式一個"HIW"「乘虛御空」"NOR"飄了起來，就如一片微風中的柳絮一般。\n",
        "\n$n使出"HIY"「解行遁變」"NOR"，身形左一晃、右一閃，不知怎麼的，從攻擊的間隙中鑽了出來。\n",
        "\n$n使出"HIM"「回神轉玄」"NOR"，足不點地地圍繞$N連繞三個大圈，把$N這一招避了開去。\n",
        "\n$n連旋數個大圈，跟著又是一個大圈，運起鳥渡術的"HIC"「棄阨飛霄」"NOR"，身形高高地拔了起來。\n",
        "\n$n身形飄浮，長袖翻捲，一勢"HIW"「出有入無」"NOR"，輕鬆自如地避開了$N的攻勢。\n",
        "\n$n向旁邊撲出，順勢一滾，閃到一邊。\n",
        "\n$n突然一個急轉身，$N的這一招滑到了一邊。\n",
                     });

int exert(object me, object target, string arg)
{

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge") != SKILL_NAME)
            return notify_fail("你並沒有使用【鳥渡術】。\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("$N身形恢復正常了。\n"NOR,me);
        write("技能【鳥渡術】已取消。\n");
        return 1;
    }

    if(me->query_skill("dodge")<10) return notify_fail("你的輕功\基礎不夠(10級)無法使用【鳥渡術】。\n");
    if(me->query_skill_mapped("dodge")==SKILL_NAME)
        return notify_fail("你已經在使用【鳥渡術】。\n");
    if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("你目前的身體狀況無法使用【鳥渡術】。\n");

if(!me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me :), 10))
        return notify_fail("你的鳥渡術收招動作還沒完成。\n");

    me->map_skill("dodge", SKILL_NAME);
    me->reset_action();

    message_vision(HIW"$N使出【鳥渡術】，身形輕如飛鳥，流轉如意。\n"NOR,me);
    me->receive_damage("ap",2);
    me->start_busy(1);
    return 1;
}

void delay(object me)
{
    if(!me) return;

    if(me->query_skill_mapped("dodge")!=SKILL_NAME)
    {
        //remove_call_out("delay");
        return;
    }

    if(me->query("ap")<2)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("$N身形恢復正常了。\n"NOR,me);
        tell_object(me,"你的體力不足無法繼續使用【鳥渡術】。\n");
        return ;
    }
    if(me->is_fighting()) me->receive_damage("ap",2);
        me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }
string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) { return 1; }

