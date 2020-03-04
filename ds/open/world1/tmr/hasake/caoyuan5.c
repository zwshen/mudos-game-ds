// Room: /open/world1/tmr/hasake/caoyuan5.c

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
  __DIR__"npc/sheep" : 1,
  __DIR__"npc/hasake" : 1,
]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"caoyuan6",
  "south" : __DIR__"caoyuan2",
  "east" : __DIR__"caoyuan4",
]));

	setup();
	replace_program(ROOM);
}
