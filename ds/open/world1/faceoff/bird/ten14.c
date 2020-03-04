#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","奇倪峰");

 set("long",@LONG
這裡是奇倪峰的北部, 如果從這裡往西北走就是負有盛名
的望月崖了, 再往西走則是東北澤林, 你驚嘆這裡的景色竟然
如此壯觀, 果然是第一高峰.
LONG
    );
 set("exits",([ "south":__DIR__"ten11",
		"east":__DIR__"ten13",
		"northwest":__DIR__"ten15",
    ]));
 set("objects", ([__DIR__"npc/eagle" : 4,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}