// Room: /open/world1/tmr/xiangyang/jiekou2.c

inherit ROOM;

void create()
{
	set("short", "大街口");
	set("long", @LONG
因為這兒是十字街口，所以非常熱鬧。小商小販們在向行
人吆喝著，兜售他們的商品。雖然襄陽飽受蒙古軍侵擾，但這
兒看不出人們有絲毫的緊張，好像他們已司空見慣、習以為常
了。北面和東面是小弄，許多襄陽城的老百姓住在裡面，南面
和西面是青石鋪就的大街。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kid" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"northroad2",
  "south" : __DIR__"eastroad2_n1",
  "east" : __DIR__"xiaorong1",
  "north" : __DIR__"xiaorong2",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
