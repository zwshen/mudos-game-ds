// 紫陽山第四層

inherit ROOM;

void create()
{
	set("short", "小空地上");
	set("long", @LONG
這是一個小空地，在這裡有些動物在行走，在你的四周是片小空地
，要小心一點，不然就會摔下山下。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"4f2.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
