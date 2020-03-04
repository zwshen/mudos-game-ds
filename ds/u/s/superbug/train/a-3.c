// Room: /u/s/superbug/train/a-3.c

inherit ROOM;

void create()
{
	set("short", "貧民區[北街]");
	set("long", @LONG
這裡是貧民區的北街，這裡仍充滿著令你感到嘔心的氣味，在你的西
方似乎是一間酒吧，門口掛著一幅巨大的招牌寫著「糜爛酒吧」，門口還
有幾個醉客在聊天，往南可以前往市中心。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"a-2.c",
  "north" : __DIR__"a-4.c",
  "west" : __DIR__"a-19.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
