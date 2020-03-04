// Room: /open/world1/tmr/dragoncity/southgate2.c

inherit ROOM;

void create()
{
	set("short", "朱雀外門");
	set("long", @LONG
這裡是磐龍城的南城門的外城門，只見城門上方是三個大字。

[1;36m                      朱雀門
[0m
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bridge3",
  "north" : __DIR__"southgate1",
]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
