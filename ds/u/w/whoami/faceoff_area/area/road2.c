#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"小路"NOR);
set("long",@LONG
從這裡開始, 就會進入到東北地區了, 從這裡到十萬大山, 約
莫要十天腳程,  一路上的景色越來越荒涼, 路旁的小販也看不見了
....
LONG
    );
 set("exits",([ "south":__DIR__"road1",
		"east":__DIR__"road3",
]));
 set("objects", ([__DIR__"npc/man" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
