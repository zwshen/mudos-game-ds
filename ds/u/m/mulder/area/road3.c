// Room: /u/m/mulder/area/road3.c

inherit ROOM;

void create()
{
	set("short", "新彼得城 - 廣場中心");
	set("long", @LONG
這是新彼得城的廣場中心，你可以在這�媟皎坐@下或看看這
兒漂亮的風景．向東走可以到這�堻怚X名的購物街買一些武器，
或是防具，也可在這�堻}街一番．東邊有一間銀行．
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road6",
  "north" : __DIR__"road4",
  "south" : __DIR__"road2",
  "east" : __DIR__"road5",
]));
	set("no_clean_up", 0);
 set("outdoors","land");
set("light",5);
set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/obj/pot" : 1,
]));

	setup();
	replace_program(ROOM);
}
