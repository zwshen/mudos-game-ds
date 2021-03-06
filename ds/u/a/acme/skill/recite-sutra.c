//誦經  recite-sutra
//update 2000.6.2 by -Acme-
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost,int times);

int cast(object me, object target, string arg)
{
        int rs_sk,inn,tt,addexp;
        inn=me->query_int();
        rs_sk=me->query_spell("recite-sutra");

        tt= rs_sk / 10;
        if(tt < 1) tt=1;
        if(tt > 6) tt=6;

        if(me->is_fighting() )
        {
        if(rs_sk < 30)
                return notify_fail("你尚無法引懲【六卦追雷 】。\n");
        if(me->query("ap") < (tt*15) )
                return notify_fail("依你目前的狀態，無法引懲【六卦追雷 】。\n");
        if(me->query("mp") < (tt*10) )
                return notify_fail("依你目前的狀態，無法引懲【六卦追雷 】。\n");

        if ( !target ) target = offensive_target(me);
        if(!target) return notify_fail("你要對誰引懲【六卦追雷 】？？\n");      
        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) 
                return notify_fail("你並沒有和對方在戰鬥中。\n");

        message_vision(HIB "\n$N"+ HIB "陡地退了數步，雙手合十虔誠地念了段經文。\n" NOR,me);
        me->receive_damage("ap",tt*15);
        me->receive_damage("mp",tt*10);

        if( random((rs_sk/10)+2 ) >random(15) )  
        {
        message_vision(HIC "\n忽然天空驚起一陣響雷，一道閃電不偏不倚地打在$N"+ HIC"身上！！\n" NOR ,target);
        tell_object(target,HIR "你覺得全身一陣發麻。\n" NOR );
        target->apply_condition("five-thunder", tt );
        target->start_busy(2);
        }
        else message_vision(HIY "結果什麼事也沒有發生....\n" NOR ,me);  
        me->improve_spell("recite-sutra",1 + random(1+me->query_int()/2 +me->query("level")/2));
        me->start_busy(2);
        return 1;
        }

        if(me->query("ap")<20 || me->query("mp")<20 ) 
                return notify_fail("你現在的狀態不佳，不能再念經了。\n");
        if(me->query_temp("is_busy/recite-sutra") )
                return notify_fail("你還有另一張嘴再來念經？？\n");
        if( sizeof(me->query_temp("is_busy")) ) 
                return notify_fail("你現在正在忙。\n");

        if(!target) return notify_fail("這裡沒有這個東西。\n");

        if( userp(target) ) return notify_fail("他是玩家，你無法對玩家超生。\n");

        //因為用id判斷是否為skeleton,所以加上這行,防止玩家id為skeleton

        if( !target->is_corpse() && target->query("id") != "skeleton" )
                return notify_fail("你只能對屍體唸經超生。\n");

        // 因為 is_corpse() 不能判斷 乾枯的骸骨(Skeleton) 只好用id判斷

        if( target->query("recite-sutra") )
                return notify_fail("它的靈魂已達西方極樂世界。\n");
        if( me->query("evil") > 500 ) 
                return notify_fail("你過於邪惡，竟無法淨下心來為亡魂超渡。\n");

        target->set("recite-sutra",1);
        message_vision(MAG "$N宣了聲佛號，開始念誦起經文，超渡已身亡的$n。\n"NOR,me,target);

        me->start_busy(5);
        me->receive_damage("mp", 20 );
        me->receive_damage("ap", 20 );
        me->add("evil", -target->query("level") );
        addexp=me->query_int()+me->query_sou()*3+target->query("level")+me->query("level");
        me->improve_spell("recite-sutra",addexp);

        return 1;
}
int valid_learn(object me) { return 1; }

void spell_improved(object me)
{
        int g,b,c,addexp;

        b = me->query_spell("recite-sutra",1);
        c = me->query("spell/recite-sutra");
        g = me->query("gain_bonze_exp");

        if( b > g ) {
                addexp=b*b*me->query_int() - (int)me->query("evil")*10;
                tell_object(me,HIG "你因誦經頗有心得，得到了"+ addexp +"點經驗值。\n"NOR);
                me->add("exp",addexp);
                me->set("gain_bonze_exp",b);
        }
        if(b > c && b % 15 == 0 && random(b) > 15 )
        {
                tell_object(me, HIC "你因誦經而修出正道，你的智慧提升了。\n" NOR);
                me->add("addition/int", 1);
                me->set("spell/recite-sutra",b);
        }
        me->save();
}
