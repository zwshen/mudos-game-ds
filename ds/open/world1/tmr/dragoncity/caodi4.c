// Room: /open/world1/dragoncity/caodi4.c

inherit ROOM;

void create()
{
	set("short", "奧特蘭克-草地");
	set("long", @LONG
這兒是奧特蘭克山谷外的大草地，往北可以望見少帥軍
與虎人鐵櫻族終年爭戰的主要戰地－奧特蘭克山谷，雖然這
兒沒有半點戰火，但四週氣氛卻是充滿金屬肅殺之氣。
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"northgate2",
  "north" : __DIR__"caodi2",
]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
