// File: /d/duli_port/map_11_10.c
// Updated by tmr (Thu Feb 28 01:52:45 2002)

inherit ROOM;

void create()
{
	  set("short", "中央廣場");
	  set("long", @LONG
這裡是一處佔地頗大的中央廣場，南北向的道路，人來人往，十分的
熱鬧。廣場中央還擺了個大水缸，供口渴的路人喝水用。
LONG
	  );
	  set("map_long", 1);
	  set("objects", ([ /* 1 element(s) */
	__DIR__"obj/pot" : 1,
]));
        set("no_fight",1);
	  set("exits", ([ /* 4 element(s) */
	"east" : __DIR__"map_11_11",
	"north" : __DIR__"map_10_10",
	"west" : __DIR__"map_11_9",
	"south" : __DIR__"map_12_10",
]));
	  set("outdoors", "land");

	setup();
	load_object("/daemon/board/duli_board");
	load_object("/daemon/board/duli_board");
}
