#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "黃沙陵");
	set("long", @LONG
你身處在黃沙陵之上，四周盡是風飛沙，你發覺身子慢慢的往下墜入
黃沙之中，便似有隻手在拉著你，你心中不禁的想起是否日前所殺之人的
冤魂來索命了，你的手抖動著，卻是不寒而慄，還是快快離開此處較好。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hills",
  "south" : __DIR__"hills2",
  "southeast" : __DIR__"senwu1" ,
]));
	set("no_clean_up", 0);
  set("no_recall",1);
  set("no_goto",1);
    set("outdoors","land");

	setup();
}
void init()
{
  object me;
  me=this_player();      
  add_action("do_jump","jump");
  me->start_busy(2);
  me->set_temp("quicksand",1);
  me->set_temp("time",6);
  message_vision(HIR "\n忽然間，$N的雙腳竟陷進了流沙之中....\n" NOR,me);
  call_out("down_msg",1,me);
}
int do_jump(string arg)
{
        object me;
        me=this_player();
        if(!me->query_temp("quicksand")) return 0;
        if(arg!="up") return notify_fail("你正在下陷中，還是往上(up)跳得好吧..\n");
        if(me->query_skill("dodge") > 15 )
        {
          message_vision(HIW"只見$N奮力的掙扎，努力得要跳出這可怕的流沙。\n"NOR,me);
          me->set_temp("jumpok",1);
        }
        else
        {  
          message_vision(HIW"只見$N奮力的掙扎，努力得要跳出這可怕的流沙。\n"NOR,me);
          message_vision(HIC"$N使盡渾身解數，卻無法掙脫，只是越陷越深。\n"NOR,me);
        }
     return 1;
}

int down_msg(object me)
{
        int i;
        if(!me) return 1;
        me->start_busy(3);
        i=me->query_temp("time");
        me->set_temp("time",i-2);
        if(!me->query_temp("jumpok") )
        {
                tell_object(me,HIR "你發覺你的身子慢慢的往下墜。\n"NOR);

                if (i>=0)
                        call_out("down_msg",3,me);
                else
                {
                 me->move(__DIR__"howe");
        message_vision(HIW "$N「哇」的一聲，重重地由上掉落到沙表下的洞穴。\n"NOR,me);
                me->delete_temp("jumpok");
                me->delete_temp("quicksand");
                me->delete_temp("time");
               }

        }
        else {
tell_object(me,HIC "你使出深厚的輕功\，身成蛟龍之勢，奮力的往上一躍，從流沙裡跳了出來。....\n"NOR);
                me->delete_temp("jumpok");
                me->delete_temp("quicksand");
                me->delete_temp("time");
        }
        return 1;
}
