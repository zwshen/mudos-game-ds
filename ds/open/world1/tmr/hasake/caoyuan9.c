// Room: /open/world1/tmr/hasake/caoyuan9.c

inherit ROOM;

void create()
{
	set("short", "大草原");
	set("long", @LONG
你走進了這遍綿綿不絕的大草原，腳下是寸厚的青草，軟綿綿的還真
不好走，看來買匹馬來代步到是的好主意。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/sheep" : 2,
  __DIR__"npc/hasake" : 1,
]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"caoyuan2",
  "south" : __DIR__"caoyuana",
  "east" : __DIR__"caoyuan7",
]));

	setup();
	replace_program(ROOM);
}
