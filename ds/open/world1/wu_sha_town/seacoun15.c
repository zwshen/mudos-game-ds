#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","狥め現场");
set("long",@LONG
硂柑琌現场狥め現场, 盡快瞶ち簿﹡ㄆ叭, ┬
丁いァ碞琌狥め現﹛
LONG
    );
 set("exits",([ "south":__DIR__"seacoun14",
]));
 set("objects", ([__DIR__"../npc/east_master" : 1,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
