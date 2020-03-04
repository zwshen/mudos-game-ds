// Room: /u/m/mulder/area/road10.c

inherit ROOM;

void create()
{
	set("short", "新彼得城 - 訓練所走廊");
	set("long", @LONG
歡迎你來到訓練所！你可在這�媔i行訓練，來提升自己的水
平，希望你能成功吧！！
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road9",
  "south" : __DIR__"road15",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/master.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
