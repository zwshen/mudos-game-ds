// Room: /u/s/superbug/train/r-2.c

inherit ROOM;

void create()
{
	set("short", "鐵路內部");
	set("long", @LONG
一踏進這裡，彷彿踏進了另一個世界一樣，身後的光亮和眼前的黑暗
成強烈的對比，你不禁想退後一步回到月台上。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r-3.c",
  "south" : __DIR__"r-1.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
