// Room: /u/a/alickyuen/area/dr24.c

inherit ROOM;

void create()
{
	set("short", "ST。Livesaving＠Door");
	set("long", @LONG
這�堳K是這間醫院的急症室，你發現急症室的工作燈是長期亮著，可
想而之有很多人因意外入院。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dr23",
]));
set("objects", ([
__DIR__"npc/wnurse" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
