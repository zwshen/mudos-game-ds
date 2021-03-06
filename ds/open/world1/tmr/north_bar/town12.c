// Room: /open/world1/tmr/north_bar/town12.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－街道");
	set("long", @LONG
這裡的旁邊是市集，有許多攤販的叫賣聲以及喧嘩聲，市集 
裡有倒有賣不少土產，附近也有間藥鋪。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/villager" : 2,
]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"town10",
  "east" : __DIR__"town6",
  "north" : __DIR__"town14",
  "west" : __DIR__"town18",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
