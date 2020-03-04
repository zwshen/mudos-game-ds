// Room: /open/world1/tmr/dragoncity/shop.c

inherit ROOM;

void create()
{
	set("short", "當舖");
	set("long", @LONG
這裡是磐龍城中的一間當鋪，你可以看到在門口的兩側，
寫著『公平交易，童叟無欺』八個金漆大字。
LONG
	);
	set("no_clean_up", 0);
      set("objects", ([ __DIR__"npc/hu-mai" :1,]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"northroad1e",
]));
	set("current_light", 1);
	set("light", 1);
	set("room_type", "shop");

	setup();
	replace_program(ROOM);
}
