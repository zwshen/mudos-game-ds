// File: /d/duli_village/sea_room.c
// Updated by tmr (Tue May  7 20:42:04 2002)

inherit ROOM;

void create()
{
	  set("short", "大海洋底下");
	  set("long", @LONG
你正潛游在一片水藍藍的海洋底下，你身處在這個寂靜的世界上，慢
慢地已經分不清東南西北了，微微波動的海流正輕拂過你的身軀。
LONG
	  );
	  set("exits", ([ /* 4 element(s) */
	"north" : __DIR__"sea_room",
	"south" : __DIR__"sea_room",
	"east" : __DIR__"sea_room1",
	"west" : __DIR__"sea_room2",
]));

	setup();
	  replace_program(ROOM);
}
