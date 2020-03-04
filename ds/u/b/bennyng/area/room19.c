// Room: /u/b/bennyng/area/room19.c

inherit ROOM;

void create()
{
	set("short", "冰雪路徑");
	set("long", @LONG
受到寶瓶座聖鬥士的影響，這裡的氣溫急劇下降．整條路都被凍氣所
包圍，如果你不穿多一件毛衣，恐怕會著涼呀！！
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"room18",
  "south" : __DIR__"room20",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
