// 紫陽山第三層

inherit ROOM;

void create()
{
	set("short", "紫陽山小坡");
	set("long", @LONG
這是一個小坡，你看到再接下來就到了山頂了，心中有些的喜悅，
看看剛剛走來的路，似乎都變的簡單許多了，路上仍然塵沙飛揚，令人
看不清楚路。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"3f2.c",
  "up" : __DIR__"4f1.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
