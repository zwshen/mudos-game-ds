#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);

 set("long",@LONG 
你又往上爬了不少了距離, 你看了看四周, 你發現你已經在
雲層之上了, 溫暖的陽光, 往你身上直撲過來, 清新的空氣, 讓
你所有的壓力獲得釋放, 你不禁羨慕起住在這峭壁上的人。
LONG
    );
 
 set("no_clean_up", 0);
 set("outdoors","land"); 
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
        return notify_fail("你要跳過什麼？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "絕世峭壁") return 0;
        if (random(me->query_skill("dodge")) >= 20){
        message_vision(WHT"只見$N施展苦練許\久的輕功\，向上一躍便消失的無影無蹤了..\n"NOR ,me);
        me->move(__DIR__"bird6.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"突然出現在你的眼前..\n",me);
        return 1;
        }
          if ( me->query("level") <= 5 ) {
                message_vision( "只見$N笨手笨腳地往峭壁頂爬去。\n"NOR ,me);
                me->move(__DIR__"bird6.c");
                me->start_busy(2);
                tell_room(environment(me),me->query("name")+"突然出現在你的眼前..\n",me);
                return 1;
        }

        message_vision(HIW"$N在那像白癡一樣的跳來跳去，看來是功\力不夠，無法躍過這面峭壁•\n"NOR ,me);
        me->start_busy(3);
        return 1;
}          


