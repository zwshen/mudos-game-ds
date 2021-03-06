// Room: /open/world1/tmr/xiangyang/eastjie2.c

inherit ROOM;

void create()
{
	set("short", "東大街");
	set("long", @LONG
這兒是很大的十字街口，北邊是東內大街，南面是一條街
道，聽說有錢人一般都住在裡面，東面通向襄陽城的青龍門，
向西可到達中央廣場。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"eastjie2_w1.c",
  "south" : __DIR__"jiedao",
  "east" : __DIR__"eastjie2_e1.c",
  "north" : __DIR__"eastroad1",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -510,
  "x" : -480,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
