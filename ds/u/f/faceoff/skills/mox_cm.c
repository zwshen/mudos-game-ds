#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cast(object me, object target, string arg)
{
        int sk,i,inn,cost,he,si;
        object *enemy;
        sk=me->query_spell("moxibustion");
        inn=me->query_int();
        if( environment(me)->query("no_cast") ) 
                return notify_fail("這裡不能針灸。\n");
        if( environment(me)->query("no_magic") ) 
                return notify_fail("這裡不能針灸。\n");

        if( sizeof(me->query_temp("is_busy")) )
                 return notify_fail("你現在正在忙，無法使用炙穴針灸哦。\n");

        if( !present("needle",me) )
                return notify_fail("你必須找把針才能使用針灸哦。\n");

        if(me->query("mp") < 20)
                return notify_fail("你目前的身體狀態無法使用「炙穴針灸」的。\n");
        if(me->is_fighting() )
                return notify_fail("戰鬥中你無暇使用「炙穴針灸」.");

        if( !me->query("env/moxibustion") || me->query("env/moxibustion") == 0 || me->query("env/moxibustion") > 4 )
                return notify_fail("請用 set moxibustion 1 使用炙穴針灸第一重功力, 如果不懂請help moxibustion.\n");

        if( (int)me->query("env/moxibustion") == 1) // 療氣訣
        {
                cost=(he)-(inn)-(sk)/2;
                si=random(inn);
                he=(inn)*2+(sk)*2;
                message_vision(CYN"\n$N閉目凝氣, 將氣勁運到手中銀針, 準備使出四重針灸之「"+HIC+"【療氣】"+NOR+"」訣。\n"NOR,me);
                message_vision(CYN"\n$N忽然清嘯一聲, 手中銀針飛點心脈, 封住了傷口的傷勢 !!\n"NOR,me);
                message_vision(CYN"\n$N的傷口漸漸止住了血流....\n"NOR,me);
                me->start_busy(2);  //施法動作時間
                me->receive_damage("mp",cost); //施法扣MP
                me->receive_heal("hp",he); // 回復HP
                me->improve_skill("moxibustion",si);
        }
        
        if( (int)me->query("env/moxibustion") == 2) // 療精訣
        {
                cost=(he)-(inn)-(sk)/3;
                si=random(inn);
                he=(inn)+(sk)*2;
                message_vision(CYN"\n$N雙手運勁, 勁透全身, 準備使出四重針灸之「"+HIC+"【療精】"+NOR+"」訣。\n"NOR,me);
                message_vision(CYN"\n$N忽然將手中銀針使得快極, 點遍丹田諸穴 !!\n"NOR,me);
                message_vision(CYN"\n$N感到一股暖氣自丹田昇上....\n"NOR,me);
                me->start_busy(2); //施法動作時間
                me->receive_damage("mp",cost); //施法扣MP
                me->receive_heal("ap",he); // 回復HP
                me->improve_skill("moxibustion",si);
        }

        if( (int)me->query("env/moxibustion") == 3) // 開天訣
        {
                cost=(he)-(inn);
                si=random(inn)+6;
                he=(inn)*2+(sk)*2;
                message_vision(CYN"\n$N運起全身靈力, 只見$N頭頂陣陣白煙冒出, 準備使出四重針灸頂級功力「"+HIC+"【開天】"+NOR+"」訣。\n"NOR,me);
                message_vision(CYN"\n$N忽然將手中銀針使得有如銀龍, 剎時將任督二脈打通 !!\n"NOR,me);
                message_vision(CYN"\n$N只覺好似一股滾水流過全身, 舒暢無比! \n"NOR,me);
                me->start_busy(3); //施法動作時間
                me->receive_damage("mp",cost); //施法扣MP
                me->receive_heal("ap",he); // 回復AP
                me->receive_heal("hp",he); // 回復HP
                me->improve_skill("moxibustion",si);
        }
        return 1;
}
