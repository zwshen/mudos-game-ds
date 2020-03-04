// Room: /u/k/kenshin/sha-zin-gu/room13.c

inherit ROOM;

void create()
{
	set("short", "防具店");
	set("long", @LONG
來到了防具店，看到了一位美麗的女老闆和藹可親的對待每一位
來到此店的人，聽當地的居民說，這位女老闆未婚，未婚的你，是否
會動心呢.......?
LONG
	);
	set("current_light", 2);
	set("light", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/npc/eqboss" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
