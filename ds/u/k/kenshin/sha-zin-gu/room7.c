// Room: /u/k/kenshin/sha-zin-gu/room7.c

inherit ROOM;

void create()
{
	set("short", "田間小路");
	set("long", @LONG
走在暇日谷的田間小路上，看到一片金黃色的稻田，不免讓人驚嘆
真是豐收啊!!除了覺得豐收，也讓人感覺之所以如此，也是暇日谷的農
夫一點一滴的耕耘，才會有這樣子的結果。
LONG
	);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room8",
  "south" : __DIR__"room6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
