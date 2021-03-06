// Room: /tmr/future/hunter_forest/forest3.c

inherit ROOM;

void create()
{
	set("short", "森林小路");
	set("long", @LONG
你正走在森林中的一條小路，往西南不遠處，隱隱約約可以看到森林
的出口所在。順著小路往北走去，可以看見有著一層層的淡霧濔漫著林間
，不時可以聽見「骨」、「骨」的動物叫聲傳來。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"forest2",
	  "north" : __DIR__"forest5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("world", "future");

	setup();
	replace_program(ROOM);
}
