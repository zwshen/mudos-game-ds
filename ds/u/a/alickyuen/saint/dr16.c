// Room: /u/a/alickyuen/area/dr16.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Corridor");
	set("long", @LONG
你來到了醫院三樓的中心，這�埵陷X條路可行。往東是一排病房的所
在地，西方是電腦教學室，用來教導人們一些醫學常識，而想找醫生或一
些工作人員側要去南邊的工作室。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/nurse" : 1,
]));
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"dr27",
  "north" : __DIR__"dr15",
  "west" : __DIR__"dr25",
  "east" : __DIR__"dr17",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
