// Room: /u/d/darkfool/area1/doctor.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"s3",
]));

	setup();
	replace_program(ROOM);
}
