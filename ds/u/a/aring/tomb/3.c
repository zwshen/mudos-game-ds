// Room: /u/a/aring/tomb/3.c

inherit ROOM;

void create()
{
	set("short", "大墓園－石板道");
	set("long", @LONG
這裡是大墓園中的一條石板道，路上有零星分布的石板，走起來
較為平坦，石板與石板間長滿了齊膝的雜草，不曉得會不會有蛇
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"2.c",
  "east" : __DIR__"4.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
