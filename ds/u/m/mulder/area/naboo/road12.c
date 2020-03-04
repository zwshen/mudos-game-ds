// Room: /u/s/sonicct/area/road12.c

inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
這裡開始就進入了叢林的範圍。你可以聞得到一些由叢林花
草的香味和聽到一些鳥兒的叫聲，令你不禁停在這裡欣賞這些大
自然美景。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road11",
  "west" : __DIR__"gate4",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
