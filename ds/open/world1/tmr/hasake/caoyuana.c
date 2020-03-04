// Room: /open/world1/tmr/hasake/caoyuana.c

inherit ROOM;

void create()
{
	set("short", "草原邊緣");
	set("long", @LONG
這裡是大草原和沙漠接壤之地，青草由稀至密，向西綿綿延伸而去。
地上有幾行駱駝踏過的蹄印，看樣子這裡常常有商隊來往。西南方好像有
些炊煙。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"caoyuan9",
]));

	setup();
	replace_program(ROOM);
}
