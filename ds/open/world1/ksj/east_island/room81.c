#include <room.h>
inherit ROOM;

void create()
{
 set("short","小路");
 set("long",@LONG
這裡是櫻花林與竹林之間一段短短的泥巴小路，站在這裡到覺得
安靜許多，看著頭頂蔚藍的天空心情也舒緩多了。
LONG);
   set("exits",([ 
       "west":__DIR__"room82",
       "northeast":__DIR__"room78",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            
