// Room: /u/a/aring/tomb/16.c

inherit ROOM;

void create()
{
	set("short", "大墓園－墳墓");
	set("long", @LONG
你正站在一座墳墓的上頭，這個墳墓較為整齊，上面覆蓋著光滑的
石板，墳上的十字架則是用純白色石頭雕成，只不過石縫中長了一
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"17.c",
  "east" : __DIR__"15.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
