// Room: /open/world1/tmr/hasake/caoyuan8.c

inherit ROOM;

void create()
{
	set("short", "大草原");
	set("long", @LONG
你走進了這遍綿綿不絕的大草原，腳下是寸厚的青草，軟綿綿的還真
不好走，看來買匹馬來代步到是的好主意。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"caoyuan7",
  "south" : __DIR__"room-che",
  "east" : __DIR__"hsk",

]));

	setup();
	replace_program(ROOM);
}
