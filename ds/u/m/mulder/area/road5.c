// Room: /u/m/mulder/area/road5.c

inherit ROOM;

void create()
{
	set("short", "新彼得城-街道");
	set("long", @LONG
這是新彼得商店街的其中一部份．你可在這條街買你想買
的東西．北邊是一間銀行，而南邊是一間武器店．　
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road3",
"north" : __DIR__"bank",
"south" : __DIR__"weaponshop",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
