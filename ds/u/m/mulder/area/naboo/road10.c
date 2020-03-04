// Room: /u/s/sonicct/area/road10.c

inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
這裡是Naboo裡的大街，在北面可以去到防具店，可以自由購
買想要的貨品。而東面通去Naboo的中心，西面則可以到叢林。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"middle",
  "north" : __DIR__"shop3",
  "west" : __DIR__"road11",
  ]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
