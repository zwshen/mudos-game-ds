// Room: /open/world3/tmr/hunter_forest/hole1.c

inherit ROOM;

void create()
{
	set("short", "山洞裡");
	set("long", @LONG
你正縮在這個山洞的洞口，藉著微弱的光線，勉強能看到前方分了三
條通道。
LONG
	);
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"hole4",
  "north" : __DIR__"hole3",
  "out" : __DIR__"forest6",
  "northwest" : __DIR__"hole2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
