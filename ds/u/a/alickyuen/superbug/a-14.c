// Room: /u/s/superbug/train/a-14.c

inherit ROOM;

void create()
{
	set("short", "貧民區[南街]");
	set("long", @LONG
這裡是貧民區的南街，這裡仍充滿著令你感到嘔心的氣味，在你的西
方有間櫥窗掛滿武器的武器店，招牌上寫著大大的「末日」兩個字，看起
來似乎有一點令你感到恐怖，往北可以前往市中心。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"a-13.c",
  "south" : __DIR__"a-15.c",
  "west" : __DIR__"a-21.c",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
