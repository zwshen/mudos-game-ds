// 紫陽山第一層

inherit ROOM;

void create()
{
	set("short", "紫陽山");
	set("long", @LONG
你現在在紫陽山的山路上，路上崎嶇不平，難以行走，在你的身旁
就是山壁了，在雨天時常有落石落下，因此在下雨時這裡就變得特別危
險了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"1f2.c",
  "up" : __DIR__"2f1.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}