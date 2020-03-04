// Room: /open/world1/acme/bonze/b3.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
天色朦朧，越發淒涼沉寂，那斷斷續續的狼嚎猿啼，虎嘯獅吼，
畫破死寂的天空，更增分寒意。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"b4",
  "northwest" : __DIR__"b2",
]));
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
