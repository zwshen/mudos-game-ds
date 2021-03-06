// Room: /open/world1/tmr/xiangyang/westjie3.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
這是一條寬闊的青石街道，向東西兩頭延伸。西面是白虎
內門，東邊是一個大十字街口，只見人來人往，絡繹不絕。南
邊是大校場。北面是襄陽城的西兵營，隱隱能聽見裡面傳來的
宋兵的操練聲。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"westgate1",
  "south" : __DIR__"dajiaochang",
  "east" : __DIR__"westjie2_w1.c",
  "north" : __DIR__"bingying4",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -500,
  "x" : -540,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
