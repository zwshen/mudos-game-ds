#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","修船廠");
set("long",@LONG
雖然無砂三年前就有修船廠的設置, 不過林繁榮到任後的
大翻修才是效率極高的主因, 雖然無砂的修船廠不大, 但所有
的設備卻一應俱全. 
LONG
    );
 set("exits",([ "north":__DIR__"seacoun36",
		"west":__DIR__"seacoun34",
]));
 set("objects", ([__DIR__"npc/worker3" : 3,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}            