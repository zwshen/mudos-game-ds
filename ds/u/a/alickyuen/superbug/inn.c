// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "休息間");
	set("long", @LONG
這裡是這間旅館的休息間，你從窗口看出去，看到一些惡劣的環境，
這裡還有一些椅子（ｃｈａｉｒ），你可以坐在上面休息（ｒｅｓｔ）。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"a-17",
]));
set("light",1);
set("no_exert",1);
set("no_cast",1);
set("no_fight",1);
set("no_kill",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}
void init()
{
        add_action("do_rest","rest");
}

int do_rest()
{
        object me;
        me=this_player();
        if( me->query_temp("sleep") <= 0 )
        {
                write("你所能休息的次數已用光了！\n");
                return 1;
        }
        if(me->query_temp("sleeping"))
        {
                write("你正在睡覺。\n");
                return 1;
        }
        message_vision("$N坐在椅子上，不知不覺間就睡著了∼\n\n", me);
        me->disable_player_cmds("你正在睡覺。\n");
        me->set_temp("sleeping","你正在睡覺。");
        me->start_busy(6);
        call_out("sleep1",3,me);
        call_out("sleep2",8,me);
        call_out("wakeup",15,me);
        return 1;
}

void sleep1(object me)
{
        if(!me) return;
        me->receive_heal("hp",me->query_con()*3);
        me->receive_heal("ap",me->query_con()*2);
        me->receive_heal("mp",me->query_int()*2);
        return;
}
void sleep2(object me)
{
        if(!me) return;
        me->receive_heal("hp",me->query_con()*3);
        return;
}

void wakeup(object me)
{
        if(!me) return;
        message_vision("$N突然被旁邊的小鬧鐘吵醒了，醒了過來。\n",me);
        me->enable_player_cmds();
        me->delete_temp("sleeping");
        me->receive_heal("hp",me->query_con()*3);
        me->receive_heal("mp",me->query_int()*3);
        me->receive_heal("ap",me->query_con()*2);
      me->add_temp("sleep",-1);
        return;
}
