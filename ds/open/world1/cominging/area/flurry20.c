inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
這裡是花園旁邊的一個小舍外，在小舍的外面種有比花園中間更多的
花朵，小舍是由竹木所建成，也建得比較高了些，因為在花園常常有一些
蛇類動物出現，小舍外還有一些木桌。
LONG
	);
	set("exits", ([
  "westdown" : __DIR__"flurry15.c",
  "east" : __DIR__"flurry21.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
