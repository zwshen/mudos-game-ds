inherit ROOM;

void create()
{
	set("short", "村子西邊小路");
	set("long", @LONG
你正站在村外的小路上。這條小路的東邊就是伏克村，而遠遠的
西北邊有一座小山，出奇的是，小山的附近光禿禿的，一棵樹都沒有
，讓人有點疑惑。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"burg4",
  		"northwest" : __DIR__"burg10",
	]));

	setup();
	replace_program(ROOM);
}
