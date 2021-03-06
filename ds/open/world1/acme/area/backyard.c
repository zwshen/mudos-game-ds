// Room: /u/a/acme/area/backyard.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "後院");
        set("long", @LONG
這裡是小屋後方的院子，院子裡養了多隻鴨子，院子左方是條小溪，
有位村婦在此洗著衣物，中央有個荒廢多時的古井，古井四周也已佈滿了
草藤。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hunter",
]));
    set("objects",([
       __DIR__"npc/woman2" : 2,
       __DIR__"npc/duck" : 4,
   ]) );
    set("item_desc", ([ /* sizeof() == 1 */
          "east" : (: look_door,     "east" :),
]));
    set("item_desc", ([ /* sizeof() == 1 */
     "古井" : "這個古井頗為破舊，往下一看卻不是很深，若你有勇氣，可試著"+HIW+"往下跳。\n"NOR,
    ]));
        set("no_clean_up", 0);
    set("outdoors","land");
        setup();
create_door("east", "木門", "west", DOOR_CLOSED);
}
void init()
{
        add_action("do_jumpdown","jumpdown");
        add_action("do_jump","jump");
}
int do_jumpdown(string arg)
{
        object me;
        me=this_player();
          if(arg != "古井" && arg != "well")
        {
            notify_fail("什麼？\n");
            return 0;
        }
        else {
        message_vision("$N大叫一聲，往古井裡跳下去！！\n",me);
        me->move(__DIR__"oldwell");
        return 1;
             }
}
int do_jump(string arg)
{
        object me;
        me=this_player();
          if(arg != "down 古井" && arg != "down well")
        {
            notify_fail("什麼？\n");
            return 0;
        }
        else {
        message_vision("$N大叫一聲，往古井裡跳下去！！\n",me);
        me->move(__DIR__"oldwell");
        return 1;
             }
}
