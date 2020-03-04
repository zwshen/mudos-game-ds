#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"走廊"NOR);
 set("long",@LONG
這裡再往東走就是天梟冶藥一派的大廳了, 南方是你剛走過
來的方向, 這裡的走廊上有著一具具的草人, 想必是留給剛入門
的弟子練習針灸用的. 
LONG);
 set("exits",([ "southwest":__DIR__"pill2",
                "northwest":__DIR__"pill4",
                "east":__DIR__"pill5",
    ]));
// set("objects", ([__DIR__"npc/traveller" : 2,
//    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}

