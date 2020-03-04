// Room: /u/m/mulder/area/road6.c

inherit ROOM;

void create()
{
	set("short", "新彼得城 - 廣場大道");
	set("long", @LONG
這裏可以通往警察局或是到這裏最大的訓練場，而你可以返
回商店街買回一些強勁的武器，或是防具，或是把自己練強一點
再回來這裏吧． 往南走可以到這裏的警察局．北邊是廢車場．
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"shop2",
  "south" : __DIR__"shop1",
  "east" : __DIR__"road3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
