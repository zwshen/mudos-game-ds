#include <room.h>
inherit ROOM;

void create()
{
 set("short","農田");
 set("long",@LONG
這邊的農田裡種了許多蔬菜，有紅蘿蔔、小黃瓜、蔥、白菜等，
看起來都生長的很好，一片青翠。
LONG);
   set("exits",([ 
       "west":__DIR__"room28",
       "south":__DIR__"room22",
       "north":__DIR__"room24",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            
