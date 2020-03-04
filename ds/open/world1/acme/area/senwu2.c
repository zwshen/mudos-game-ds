// Room: /open/world1/acme/area/senwu2.c

inherit ROOM;

void create()
{
	set("short", "黃土小徑");
	set("long", @LONG
你正走在黃土小徑上，四周景物依舊，但卻覺得十分燥熱，此熱
氣不知從何傳來，直熱得冒出一身汗。環顧四方，入眼的只有黃色的
沙土，並無特別之處，令人覺得淒涼。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"senwu3",
  "west" : __DIR__"senwu1",
]));
	set("world", "past");
    set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
