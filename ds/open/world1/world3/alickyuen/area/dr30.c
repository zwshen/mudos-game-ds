// Room: /u/a/alickyuen/area/dr30.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Restroom");
	set("long", @LONG
這裏是一間醫生和護士們的休息室，又是茶水間，很多醫生和護士都
在休息時間時來這裏休息一下和喝一杯東西。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"dr27",
]));
set("objects", ([
__DIR__"npc/wnurse.c" : 1,
]));
	set("world", "future");
set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
