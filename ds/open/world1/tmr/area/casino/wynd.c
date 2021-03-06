// Room: /u/t/tmr/area/wynd.c

inherit ROOM;

void create()
{
	set("short", "小巷子");
	set("long", @LONG
你正走在一條位於頗陰暗的小巷子，在光天白日之下，此巷卻因兩旁
的房屋而阻擋了大部份陽光的照射，更突顯出巷子裡的一片寂寥。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wynd2",
  "east" : __DIR__"street5.c",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
