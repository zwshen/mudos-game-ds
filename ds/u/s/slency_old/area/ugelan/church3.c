// Room: /u/s/slency/area/ugelan/church3.c

inherit ROOM;

void create()
{
	set("short", "長型廣場");
	set("long", @LONG
這裡是一座相當大的廣場，廣場中央有一座頗大的池子，池子中央
有許多白石雕刻而成的藝術品，和這一望無際的大地藍天構成了一幅美
麗自然的圖畫，由此往西往東都是廣場。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"church2",
  "east" : __DIR__"church4",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
