// Room: /open/world1/tmr/dragoncity/caodi7.c

inherit ROOM;

void create()
{
	set("short", "奧特蘭克-草地");
	set("long", @LONG
這兒是奧特蘭克山谷外的大草地，往北可以望見少帥軍
與虎人鐵櫻族終年爭戰的主要戰地－奧特蘭克山谷，雖然這
兒沒有半點戰火，但四週氣氛卻是充滿金屬肅殺之氣。從這
兒往西是一處上山的山道，而往西北延伸過去，可見到一處
大草原。
LONG
	);
	set("outdoors", "land");
	set("current_light", 5);
	set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"caodi9",
  "south" : __DIR__"caodi6",
  "east" : __DIR__"caodi7e",
  "west" : "/open/world1/manto/pudu_mountain/way01",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
