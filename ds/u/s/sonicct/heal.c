//By SonicCT&Mulder
//1999.10.18
#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
        if(arg=="off" )
        {
		if(!me->query_temp("is_busy/heal") ) return notify_fail("你現在並沒有醫療。\n");
	        message_vision("\n"HIW"$N緩緩的睜開眼睛，看起來十分有精神。\n"NOR,me);
		me->delete_temp("is_busy/heal");
                return 1;
        }
	if(me->is_ghost() ) return notify_fail("你還是鬼魂。\n");
	if(me->is_fighting() ) return notify_fail("你正在戰鬥，無法醫療。\n");
	if(me->is_busy() ) return notify_fail("(你的上一個動作還沒有完成。)\n");
	if(me->query("hp")>=me->query("max_hp") ) return notify_fail("你現在的生命狀況已經到達顛峰了。\n");
	if( sizeof(me->query_temp("is_busy")) ) return notify_fail("你現在正在忙。\n");
	if(!me->skill_active( "heal",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("你結束醫療術的動作還沒完成。\n");
        message_vision("\n"HIW"$N盤膝而坐，感到自己的內息在身體上遊動，開始進入醫療狀態。\n"NOR,me);
        me->set_temp("is_busy/heal","你正在醫療不能移動。");
        me->start_busy(5);
       return 1;
}

void delay(object me,int cost)
{
        if(!me) return;
        if(!me->query_temp("is_busy/heal") )
        {
	         return;
        }

        if(me->query("hp")>=me->query("max_hp"))
        {
	        message_vision("\n"HIW"$N緩緩的睜開眼睛，看起來十分有精神。\n"NOR,me);
		me->delete_temp("is_busy/heal");
		return;
        }
        
        if(me->is_fighting())
        {
	        message_vision("$N由於突然受到攻擊，走火入魔，而吐了一口鮮血。\n"NOR,me);
		me->receive_damage("hp",5);
		me->delete_temp("is_busy/heal");
		me->start_busy(1);
		return;
        }

        
        if( random(me->query_skill("heal",1)+20) < 10 || random(10)==0 )
        {
        	message_vision("$N抽慉了一下，滿頭大汗，似乎有點走火入魔了。\n",me);
                me->receive_damage("hp",10);
	}
	 else
	{
		me->receive_heal("mp", 3+(me->query_int()/2)+random(me->query_skill("heal")));
	 	me->receive_heal("hp", 5+(me->query_con()/2)+random(me->query_skill("heal")));
     		me->receive_heal("ap", 3+(me->query_dex()/2)+random(me->query_skill("heal")));
        	me->improve_skill("heal",1 + random(1+me->query_int()/2));
	}

        me->skill_active( "heal",(: call_other, __FILE__, "delay", me ,5:), 5);
}

int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }
