// Room: /open/world1/tmr/area/wa7.c

inherit ROOM;

void create()
{
	set("short", "朝天湖－水裡");
	set("long", @LONG
你正在朝天湖裡，只見四週儘是青藍一片，可清晰看到不少的生物，
湖裡景色倒也不輸陸地；只是周圍景色大都一致，實不知東南西北各是通
向何方。
LONG
	);
	set("world", "past");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jellyfish" : 4,
]));
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"wa1",
  "down" : __DIR__"wa8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
