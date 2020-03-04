// Room: /open/world1/dragoncity/walln1.c

inherit ROOM;

void create()
{
	set("short", "石階");
	set("long", @LONG
這是登向城頭的石階，因為城牆很高，所以很陡。石階兩
側有可供拉車上下的斜坡道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"walle",
  "north" : __DIR__"walle2",
  "south" : __DIR__"walle3",
  "westdown" : __DIR__"eastgate1",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
