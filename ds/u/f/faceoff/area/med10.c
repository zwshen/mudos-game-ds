#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short",HIR"溫室"NOR);

 set("long",@LONG
這裡是溫室的盡頭了, 往東就會離開這個溫室, 而往西就會
回到溫室當中, 而這裡的溫度和熱甕旁邊完全一樣, 讓你對天梟
的技術見識到了許多.
LONG
    );
 set("exits",([ "east":__DIR__"med11",
		"west":__DIR__"med7",
		"north":__DIR__"med9",
    ]));
create_door("east","竹門","west",DOOR_CLOSED);
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}
