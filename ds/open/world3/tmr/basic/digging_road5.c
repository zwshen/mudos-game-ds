// Room: /future/area/digging_road5.c

inherit ROOM;

void create()
{
	set("short", "礦區廢鐵路");
	set("long", @LONG
你正在一條礦區的廢鐵路上，為由舊世界殘留下來的鋼合金鐵路，雖
已歷經好幾十年，仍然光亮如新，已廢而不用。往西順著鐵路走下去，會
到達採礦區，往南可回到礦區。
LONG
	);
	set("world", "future");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"digging_road6",
  "south" : __DIR__"digging_road4",
]));
	set("outdoors", "desert");

	setup();
	replace_program(ROOM);
}
