#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","小路");

 set("long",@LONG
你好不容易在峭壁上找到一處稍微凸出的岩石, 於是你決定
你在這荒涼的土地中, 隱約的看到這裡有人走過的樣子, 於是你
便尋著這條路繼續往前走, 你看了看四周, 在你的腳邊有一個小
鐵牌, 附近連個小草野花都沒有, 你想想這到底有誰住呢?
LONG
    );
 set("item_desc",(["鐵牌":"
你朝這鐵牌看了看, 看到了血紅色的字\n

 "HIR"天梟教    閒人請勿進入"NOR"\n

你覺得寫這"HIR"血紅色"NOR"的字的人就在不遠處\n",

     ]));
 set("exits",(["east":__DIR__"bird9",
               "west":__DIR__"bird7",
     ]));
 set("outdoors","land"); 
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           

