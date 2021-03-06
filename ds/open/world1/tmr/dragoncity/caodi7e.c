// Room: /open/world1/tmr/dragoncity/caodi7e.c

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
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"caodi8",
  "west" : __DIR__"caodi7",
]));
	set("current_light", 4);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
