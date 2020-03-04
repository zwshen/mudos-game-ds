#include <room.h>
inherit ROOM;
void create()
{
 set("short","往山腰的路上");
 set("long",@LONG
從此開始就是登山的路了, 看起來離山頂的路雖然不陡,
可是卻十分的長. 山頂被雲霧籠罩住一半, 山上到底有什麼
東西你看的不是十分清楚.
LONG
    );
 set("exits",([ "northwest":__DIR__"mountdown3",
                "west":__DIR__"mountdown4",
		"southeast":__DIR__"mountdown6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}