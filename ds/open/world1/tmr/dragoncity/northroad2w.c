// Room: /open/world1/tmr/dragoncity/northroad2w.c

inherit ROOM;

void create()
{
	set("short", "大街口");
	set("long", @LONG
這兒是北城內的十字街口，非常熱鬧，小商小販們在向
行人吆喝著，兜售他們的商品。雖然磐龍飽受虎人軍侵擾，
但這兒看不出人們有絲毫的緊張，好像他們已司空見慣、習
以為常了。北面和西面是胡同，許多磐龍城的老百姓住在裡
面，東面和南面是青石鋪就的大街。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"westroad",
  "east" : __DIR__"northroad2",
]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
