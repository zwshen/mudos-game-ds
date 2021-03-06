// Room: /u/a/alickyuen/area/dr23.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Corridor");
	set("long", @LONG
這裡人來人往，都是經由大堂送病人去到急症室，看到病人辛苦的表
情，你好像有點同情他們，亦不想他們死去。這裡來往的男女護士都是非
常年輕的，令到有很多少男少女看著他們工作，瞪大眼睛的看著。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dr24",
  "east" : __DIR__"dr4",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
