// Room: /open/world1/tmr/dragoncity/house4.c

inherit ROOM;

void create()
{
	set("short", "少帥府－後花園");
	set("long", @LONG
這裡是少帥府的後花園，園內假山林立，西邊種著一些青竹，東邊是
幾棵枝葉茂盛的木筆花樹。你一走進來，就聞到一陣陣清新的、淡淡的花
香，盡是粉紅色的鬱金香跟藍色的玫瑰花，花團錦蔟，美不勝收。
LONG
	);
	set("east", "house4e");
	set("no_clean_up", 0);
	set("west", "house4w");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"house4w",
  "south" : __DIR__"house3",
  "north" : __DIR__"house4n",
  "east" : __DIR__"house4e",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
