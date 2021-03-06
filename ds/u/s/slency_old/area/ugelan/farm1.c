// Room: /u/s/slency/area/ugelan/farm1.c

inherit ROOM;

void create()
{
	set("short", "幽遮蘭城外的莊園");
	set("long", @LONG
你來到了幽遮蘭城外的莊園，走在田野之中，不時可以看見很多的
莊農正努力耕種著，看到這片廣闊肥沃的農田，相信幽遮蘭城必是相當
富庶的一座大城，這裡有一條通往北邊的石路，你看到很多人在這條路
上穿梭，由這裡繼續往北走應該就是幽遮蘭城了。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"farm8",
  "west" : __DIR__"farm3",
  "north" : __DIR__"farm5",
  "east" : __DIR__"farm2",
  "meetroom" : "/u/s/slency/meetroom",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
