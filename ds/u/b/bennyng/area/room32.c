// Room: /u/b/bennyng/area/room32.c

inherit ROOM;

void create()
{
	set("short", "山羊宮與寶瓶宮交界");
	set("long", @LONG
天空突然下著一片白雪，氣溫急速下降，你不走快一步，恐怖會感冒
．往北就是寶瓶宮的入口，你不知會有什麼事情會發生．
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room33",
  "northup" : __DIR__"room31",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
