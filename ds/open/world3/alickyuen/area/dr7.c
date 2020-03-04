// Room: /u/a/alickyuen/area/dr7.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Liftdoor");
	set("long", @LONG
你來到大堂的北部，這�堿O傳送機的入口，你能夠使用傳送機來往醫
院各層或一些重要地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr6",
  "enter" : __DIR__"dr8",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
