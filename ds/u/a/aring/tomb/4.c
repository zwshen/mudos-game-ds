// Room: /u/a/aring/tomb/4.c

inherit ROOM;

void create()
{
	set("short", "大墓園－石板道");
	set("long", @LONG
這裡是大墓園中的一條石板道，路上有零星分布的石板，走起來
較為平坦，往東邊走是大墓園的東側大門。
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"3.c",
  "east" : __DIR__"5.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
