#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","屋頂上");
 set("long",@LONG
你到了一棟木屋的屋頂上, 突然看見有一位受了重傷的人
坐在那裡, 看地上的血跡, 她也許快不行了, 你可以跳下屋頂
去獵狐村.
LONG
    );
 
 set("objects",([__DIR__"npc/purpler" : 1,
               ]));
 set("outdoors","land");
 set("no_fight",1);
 set("no_clean_up", 0);
 setup();
}        

void init()
{
   add_action("do_jump","jump");
} 
int do_jump(string arg)
{        
          object me;
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("你要跳什麼？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "down" ) return 0;
        message_vision(HIR"$N不要命的往下跳後便消失的無影無蹤了..\n"NOR ,me);
        me->move(__DIR__"village15.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"從天上掉了下來•\n",me);
        return 1;
}          

