#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","石階");

 set("long",@LONG 
這裡是石階的中央, 你抬頭往天空望去, 天空的鳥類愈來愈
多了, 全部在你頭頂徘徊, 你放眼望去, 全部的城市和小鄉村, 
都盡在你的眼底, 你覺得你有高人一等的感覺, 石階往北方延伸
出去。
LONG
    );
 
 set("exits",(["northup":__DIR__"bird11",
               "southdown":__DIR__"bird9",
     ]));
 set("no_clean_up", 0); 
 set("outdoors","land"); setup();
 replace_program(ROOM);
}           

