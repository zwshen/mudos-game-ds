#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","奇倪峰");

 set("long",@LONG
這裡是奇倪峰的東邊, 只見你的西方似乎有一個小小的茅
屋, 不知道是誰住在那裡? 往北則會到奇倪峰的北部, 從那裡
再往西邊就是望月崖了.
LONG
    );
 set("exits",([	"west":__DIR__"ten12",
		"east":__DIR__"ten10",
		"north":__DIR__"ten14",
    ]));
 set("objects", ([__DIR__"npc/eagle" : 3,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}