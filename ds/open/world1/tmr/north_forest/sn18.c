// Room: /u/l/lestia/area/sn18.c

inherit ROOM;

void create()
{
	set("short", "北方大森林-小徑");
	set("long", @LONG
當你走到這裡，你發現兩旁的雜草中似乎有對陰森森的眼睛盯著你看，
但由於雜草甚高，你也看不出個所以然來，只能默默的繼續向深處走去，你
感覺你越往深處走，那雙眼睛的眼神也跟著你一起走，似乎是隨時伴隨在你
的左右，一種寒冷的感覺從你心頭竄起，使你不由得打了個冷顫。
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("objects", ([ 
__DIR__"npc/dog":2,
]));

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sn19",
  "south" : __DIR__"sn17",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
