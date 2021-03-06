#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "十二人客棧二樓");
        set("long", @LONG
這是十二客棧的二樓，在這的附近有一個培養槽，槽裡可以容納非
常多的人，在四周有許多古代所遺留的圖，在窗戶旁也有一朵朵擺飾的
花朵，令人賞心悅目，這裡可以供人休息(sleep)，可以恢復元氣。
LONG
        );
        set("exits", ([
  "down" : __DIR__"waiter.c",
]));
        set("light", 1);
        set("no_fight", 1);
        set("no_cast", 1);
        set("no_exert", 1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_sleep","sleep");
}

int do_sleep()
{
        object me;
        me=this_player();
        if( me->query_temp("sleep") <= 0 )
        {
                write("你所能休息的次數已用光了！\n");
                return 1;
        }
        if(me->query_temp("is_busy/sleeping"))
        {
                write("你正在睡覺。\n");
                return 1;
        }
        message_vision(HIW "$N打了一個大呵欠，緩緩的步入培養槽中∼\n\n" NOR, me);
        tell_object(me, HIW "眼睛一閉，隨即就在全氧的培養槽睡著了.....\n\n" NOR );
        tell_object(me, HIB "ｚＺｚＺＺＺｚＺＺＺＺＺｚｚＺＺｚ\n\n\n" NOR );
        me->disable_player_cmds("你正在睡覺。\n");
        me->set_temp("is_busy/sleeping","你正在睡覺。");
        me->start_busy(10);
        call_out("sleep1",3,me);
        call_out("sleep2",8,me);
        call_out("wakeup",15,me);
        return 1;
}

void sleep1(object me)
{
        if(!me) return;
    tell_object(me,HIG"你漸漸進入了夢鄉，見到了你喜愛的人∼\n"NOR);
        me->receive_heal("hp",me->query_con()*4);
        me->receive_heal("ap",me->query_con()*2);
        me->receive_heal("mp",me->query_int()*3);
        return;
}

void sleep2(object me)
{
        if(!me) return;
        tell_object(me,HIB"你什麼也不想了，眼前一黑，沉沉的睡了下去∼∼ｚｚｚ\n"NOR);
        me->receive_heal("hp",me->query_con()*5);
        return;
}

void wakeup(object me)
{
        if(!me) return;
        message_vision(HIW"$N突然被旁邊的老闆的開門聲給吵醒，揉了揉眼睛醒了過來。\n" NOR,me);
        me->enable_player_cmds();
        me->delete_temp("is_busy/sleeping");
        me->receive_heal("hp",me->query_con()*7);
        me->receive_heal("mp",me->query_int()*3);
        me->receive_heal("ap",me->query_con()*3);
        me->add_temp("sleep",-1);
        return;
}

