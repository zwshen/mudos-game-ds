// Room: /u/m/mulder/area/road11.c

inherit ROOM;

void create()
{
	set("short", "新彼得城 - 街道");
	set("long", @LONG
可能這附近是警察局的關係，令你不敢有做壞事的心情，而
激發起你的除暴安良心．你還要將你的所有全獻給這城市．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road14",
  "north" : __DIR__"shop1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
