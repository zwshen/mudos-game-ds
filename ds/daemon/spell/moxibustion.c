#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cast(object me, object target, string arg)
{
    int sk,i,inn,lv,wis,cost,he,si;
    object *enemy;
    sk=me->query_spell("moxibustion");
    inn=me->query_int();
    lv=me->query_level();
    wis=me->query_wis();

    if( environment(me)->query("no_cast") )
        return notify_fail("這裡不能針灸。\n");

    if( environment(me)->query("no_magic") )  // (COM) cast.c 裡面是用 no_magic, 最好也加上去
        return notify_fail("這裡不能針灸。\n");

    if( sizeof(me->query_temp("is_busy")) )
        return notify_fail("你現在正在忙，無法使用炙穴針灸哦。\n");

    if( !present("needle",me) )
        return notify_fail("你必須找把針才能使用針灸哦。\n");

    if( me->query("mp") < 20)
        return notify_fail("你目前的身體狀態無法使用「炙穴針灸」的。\n");

    if( me->is_fighting() )
        return notify_fail("戰鬥中你無暇使用「炙穴針灸」.");

    if( !me->query("env/moxibustion") || me->query("env/moxibustion") == 0 || me->query("env/moxibustion") > 4)
        return notify_fail("請用 set moxibustion 1 使用炙穴針灸第一重功\力，尚有疑問可 help moxibustion。\n");

    if( (int)me->query("env/moxibustion") == 1) // 療氣訣
    {
        he=(inn)*2+(sk)*2;
        cost=(he)-(inn)*2-(sk);
        si=random(inn/2) + (inn/4);
        message_vision(YEL"\n$N閉目凝氣, 將氣勁運到手中銀針, 準備使出四重針灸之「"+HIC+"【療氣】"+NOR+"」"+YEL+"訣。"+NOR+"\n"NOR, me);
        message_vision(YEL"\n$N忽然清嘯一聲, 手中銀針飛點$n心脈, 封住了$n傷口的傷勢 !!\n"NOR, me,target,target);
        message_vision(YEL"\n$n的傷口的血流漸漸止住了....\n"NOR,target );
        me->start_busy(2);  //施法動作時間
        me->receive_damage("mp",cost); //施法扣MP
        me->receive_heal("hp",he); // 回復HP
        me->improve_spell("moxibustion",si);
        return 1;
    }
    if( (int)me->query("env/moxibustion") == 2) // 療精訣
    {
        he=(inn)+(sk)*2;
        cost=(he)-(inn)-(sk)*2;
        si=random(inn/2) + (inn/4);
        message_vision(YEL"\n$N雙手運勁, 勁透全身, 準備使出四重針灸之「"+HIC+"【療精】"+NOR+"」"+YEL+"訣。"+NOR+"。\n"NOR,me);
        message_vision(YEL"\n$N忽然將手中銀針使得快極, 點遍$n丹田諸穴 !!\n"NOR,me,target);
        message_vision(YEL"\n$n感到一股暖氣自丹田昇上....\n"NOR,target);
        me->start_busy(2); //施法動作時間
        me->receive_damage("mp",cost); //施法扣MP
        me->receive_heal("ap", he); // 回復AP
        me->improve_spell("moxibustion",si);
    }

    if( (int)me->query("env/moxibustion") == 3) // 開天訣
    {
        he=(inn)*2+(sk)*2;
        cost=(he)-(inn);
        si=random(inn/3)+(inn/3)+5;
        message_vision(YEL"\n$N運起全身靈力, 只見$N頭頂陣陣白煙冒出, 準備使出四重針灸頂\級\功\力\「"+HIC+"【開天】"+NOR+"」"+YEL+"訣。"+NOR+"。\n"NOR,me);
        message_vision(YEL"\n$N忽然將手中銀針使得有如銀龍, 剎時將任督二脈打通 !!\n"NOR,me);
        message_vision(YEL"\n$N只覺好似一股滾水流過全身, 舒暢無比! \n"NOR, me);
        me->start_busy(3); //施法動作時間
        me->receive_damage("mp",cost); //施法扣MP
        me->receive_heal("ap",he); // 回復AP
        me->receive_heal("hp",he); // 回復HP
        me->improve_spell("moxibustion",si);
    }

    if( (int)me->query("env/moxibustion") == 4) // 善世訣
    {
        if( !userp(target) )
            return notify_fail("你只能對玩家使用療傷功\能哦。\n");
        if( target==me )
            return notify_fail(CYN"「"+HIC+"【善世】"+NOR+"」"+CYN+"訣只能對人使用."+NOR+"\n");
        if( !me->visible(target) ) // (COM) 檢查看不看的到人
            return notify_fail("這裡沒有這個人！\n");
        he=(inn)*2+(sk)*2;
        cost=(he)-(inn);
        si=random(inn/3)+(inn/3);
        message_vision(YEL"\n$N運起靈力, 氣集雙掌, 準備使出四重針灸之「"+HIC+"【善世】"+NOR+"」"+YEL+"訣。"+NOR+"。\n"NOR,me);
        message_vision(YEL"\n$N將銀針快速點過"+target->query("name")+"心脈,",me);
        message_vision(YEL" 封住"+target->query("name")+"的傷勢!\n"NOR,me);
        message_vision(YEL"\n$N感到一股熱氣壓住傷口, 頓時舒暢許\多! \n"NOR,target);
        me->start_busy(3); //施法動作時間
        me->receive_damage("mp",cost); //施法扣MP
        target->receive_heal("hp",he); // 回復AP
        me->improve_spell("moxibustion",si);
    }
    else return 0;
    return 1;
}

