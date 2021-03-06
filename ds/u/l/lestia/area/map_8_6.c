// Room: /u/l/lestia/area/map_8_6.c

inherit ROOM;

void create()
{
	set("short", "靈幻教-石板道路");
	set("long", @LONG

你正走在一條頗為寬敞的小道上，小道是用石板一塊一塊拼湊而成的，
因為年代有點久了，所以看起來有點破碎的痕跡，小道兩旁還種滿了花草
樹木，使人的眼睛為之一亮，幾隻辛勤的蜜蜂也忙著採蜜，看牠們努力的
樣子，使你也下定決心要好好的努力。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"map_8_7",
  "north" : __DIR__"map_7_6",
  "south" : __DIR__"map_9_6",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
