// Room: /open/world1/tmr/xiangyang/westjie2.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
這兒是很大的十字街口，北邊是西內大街，南面是一座彩
樓，樓前高高的掛著一方大匾，上面用正楷寫著“聚義館”，
落款“朱子柳”。東邊通向中央廣場，西面可達白虎門。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wusantong" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"westjie2_w1.c",
  "south" : __DIR__"juyiyuan",
  "east" : __DIR__"westjie1",
  "north" : __DIR__"westroad1",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -500,
  "x" : -530,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
