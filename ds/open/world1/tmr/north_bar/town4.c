// Room: /open/world1/tmr/north_bar/town4.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－街道");
	set("long", @LONG
走到這裡，旁邊幾乎都是當地居民的住宅。前方也有一些市
集、商店等，十分熱鬧。但是這裡的地板卻全都是黃土混雜
著些小石子鋪成的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town3",
  "north" : __DIR__"town5",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
