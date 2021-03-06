// Room: /u/m/mulder/area/road3.c

inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
這裡是一條筆直的街道，從這裡往西面可以找到一間旅館，
而在東邊有一間酒吧。你可以看見這裡的市民正在忙碌地工作
。往北是Naboo城的市中心。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"road2",
  "north" : __DIR__"middle",
  "west" : __DIR__"inn",
  "east" : __DIR__"bar",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
