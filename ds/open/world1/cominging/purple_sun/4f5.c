// 紫陽山第四層

inherit ROOM;

void create()
{
	set("short", "小空地上");
	set("long", @LONG
你現在在一個小空地上，在你的眼前有一個小洞，似乎可以進去裡
面去探索，這裡有點空曠，有些野獸在行走，不是十分的安全。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"4f2.c",
  "in" : __DIR__"hole2.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
