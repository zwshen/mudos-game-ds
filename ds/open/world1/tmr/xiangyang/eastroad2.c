// Room: /open/world1/tmr/xiangyang/eastroad2.c

inherit ROOM;

void create()
{
	set("short", "東內大街");
	set("long", @LONG
這是一條青石鋪就的大街。西面是一堵蓋著紅色琉璃瓦的
高牆，裡面是襄陽守城大將王堅的府邸大院。東面是忠烈祠，
因為十餘年來，為保衛襄陽、抵抗蒙古軍的侵略而犧牲的人特
別多，前往上香祭奠的人絡繹不絕。北面是一個十字街道，只
見人來人往，非常熱鬧，南面是用青石鋪的街道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"eastroad1",
  "east" : __DIR__"zhonglie",
  "north" : __DIR__"eastroad2_n1",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -490,
  "x" : -480,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
