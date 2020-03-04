#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR"－"HIW"北市街"NOR);
 set("long",@LONG
你繼續往北走, 這裡沒有半個攤位, 冷冷清清的, 街上還有
幾個老公公, 老婆婆在掃地, 在你的西方, 是一位天才織布少女
的家, 在你的東方就是十萬大山的望月崖, 在你的北方住著一戶
大戶人家.
LONG);
 set("exits",(["west":__DIR__"village16",
               "east":__DIR__"village18",
               "south":__DIR__"village13",
               "north":__DIR__"rich1",
              ])); 
 set("item_desc",([
        "東方屋頂":"你朝東方的屋頂看了過去，發覺上面好像有個人？！\n",
             
    ]));
 set("objects",([__DIR__"npc/oldman" : 1,
                 __DIR__"npc/oldwoman" : 2,
     ]));
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
        return notify_fail("你要跳上什麼？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "東方屋頂" && arg != "屋頂") return 0;
        if ( me->query_skill("dodge") >= 60){
        message_vision(WHT"只見$N施展苦練許\久的輕功\，向上一躍便消失的無影無蹤了..\n"NOR ,me);
        me->move(__DIR__"village17.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"突然出現在你的眼前..\n",me);
        return 1;
        }
        message_vision(HIW"$N在那像白癡一樣的跳來跳去，看來是功\力不夠，無法跳上這個屋頂•\n"NOR ,me);
        me->start_busy(1+random(2));
        return 1;
}          


