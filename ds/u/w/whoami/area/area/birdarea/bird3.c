#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);

 set("long",@LONG 
又過了不少時間, 你覺得這個峭壁高的驚人, 不是平常人所
能爬上來的, 你的好奇心又加深了一分, 到底在這峭壁之上有什
麼東西, 但是你的恐懼心也加深了一分, 那個長嘯的人到底是誰
呢?
LONG
    );
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}           
void init()
{
  add_action("do_jump","jump"); 
}

int do_jump(string arg)
{        
        object me,ob; 
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("你要跳過什麼？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "絕世峭壁") return 0;
        if (random(me->query_skill("dodge")) >= 30){
        message_vision(WHT"只見$N施展苦練許\久的輕功\，向上一躍便消失的無影無蹤了..\n"NOR ,me);
        me->move(__DIR__"bird4.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"突然出現在你的眼前..\n",me);
        return 1;
        }
        message_vision(HIW"$N在那像白癡一樣的跳來跳去，看來是功\力不夠，無法躍過這面峭壁•\n"NOR ,me);
        me->start_busy(3);
        return 1;
}          
