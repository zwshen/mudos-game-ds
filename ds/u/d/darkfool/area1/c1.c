// Room: /u/d/darkfool/area1/c1.c

inherit ROOM;

void create()
{
	set("short", "廣場");
	set("long", @LONG
這裡是新諾提斯鎮的廣場，東邊不遠處有一根石柱，從這裡有幾
條分岔的道路，分別通往鎮上各處。廣場的一角放了一部有銀幕的機
器。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 5 */
  "southeast" : __DIR__"31",
  "east" : __DIR__"c2",
  "west" : __DIR__"4",
  "northeast" : __DIR__"11",
  "south" : __DIR__"s1",
]));

	setup();
	replace_program(ROOM);
}
