#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大廳"NOR);

 set("long",@LONG
這裡依然可以見到那根大的離譜的柱子, 你同時也發現到
南方傳來一陣一陣燒焦的味道, 看來南方是天梟針灸一派的針
灸室, 說真的, 這股味道讓你想吐...
LONG
    );
 set("exits",([ "north":__DIR__"pill4",
                "southeast":__DIR__"pill8",
    ]));
 set("item_desc",([
        "柱子" : "一根大大的柱子.\n",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
