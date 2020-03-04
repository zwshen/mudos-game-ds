// Room: /u/b/bennyng/area/room27.c

inherit ROOM;

void create()
{
	set("short", "寶瓶宮宮頂");
	set("long", @LONG
這裡可看到聖域的觀星樓，你可以知道，原來觀星樓那邊是縣崖．
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"room24",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
