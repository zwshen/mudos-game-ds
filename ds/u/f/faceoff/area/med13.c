#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"針林"NOR);

 set("long",@LONG
這裡是針林的入口, 你抬頭上望, 發現你和天空之間有一道
淡淡的霧氣, 你忽然想起地理有一種叫寒穴的名詞, 在那裡特別
寒冷, 想來針林就是這樣的地方吧?
LONG
    );
 set("exits",([ "south":__DIR__"med14",
		"west":__DIR__"med16",
		"east":__DIR__"med12",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}