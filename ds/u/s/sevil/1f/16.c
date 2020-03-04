// Room: /u/s/sevil/1f/16.c

inherit ROOM;

void create()
{
	set("short", "寬廣的走道");
	set("long", @LONG
這裡是寬廣的走道，兩旁的商場讓你看的目不暇給，不知道
該往那邊走才對？在妳的北邊是一間有名的金鋪，專賣一些精緻
的金飾，西邊是一間著名的化妝品店，專賣一些國外的化妝品，
南邊是百貨公司的大門。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"17.c",
  "north" : __DIR__"21.c",
  "south" : __DIR__"11.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
