// Room: /u/a/acme/area/lea15.c

inherit ROOM;

void create()
{
	set("short", "大草原");
	set("long", @LONG
你身處在一片大草原之上，四周的野草已長得比人高了，腳下的泥土
也變得較為泥濘，行走相當不便。你聽見不時得傳來飛禽走獸的的叫聲。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lea5",
  "east" : __DIR__"lea16",
//有bug 暫關 "north" : __DIR__"gosky",
  "northeast" : __DIR__"pass",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
