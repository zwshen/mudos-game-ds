// Room: /open/world1/tmr/north_bar/town22e.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－書房");
	set("long", @LONG
這裡是北蠻村村長家的一間書房，室角有兩排大書櫃，
陳列了各式各樣的書籍，包括天文地理、易理術數等經典
名書。室內還擺了十來張小椅子，讓村民可以方便地在這
讀書或是開會。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"town22",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/nie" : 1,
]));
	set("no_clean_up", 0);
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
