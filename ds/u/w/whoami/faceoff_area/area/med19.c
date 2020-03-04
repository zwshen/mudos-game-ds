#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"晦林"NOR);

 set("long",@LONG
這裡是晦林的南邊, 所謂晦林就是種植需要高度溼氣才能
生長的植物的地方, 所以這裡的溼氣是相當高的, 高到令你感
到不舒服....
LONG
    );
 set("exits",([ "north":__DIR__"med18",
		"west":__DIR__"med20",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}