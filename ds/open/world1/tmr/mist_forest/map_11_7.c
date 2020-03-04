// File: /d/mist_forest/map_11_7.c
// Updated by tmr (Thu May 16 20:18:54 2002)

inherit ROOM;

void create()
{
	  set("short", "迷霧");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_12_7",
	"north" : __DIR__"map_0_9",
]));
	  set("outdoors", "forest");

	setup();
}
int valid_leave(object me, string dir)
{
        if(dir=="north") {
                //tell_object(me,"你走了老半天，竟是在原地裡打轉。\n");
                return notify_fail("你走了老半天，竟是在原地裡打轉。\n");

        }
        return ::valid_leave(me,dir);
}
