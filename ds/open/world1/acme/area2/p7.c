// Room: /u/a/acme/area3/p7.c

inherit ROOM;

void create()
{
	set("short", "拱橋");
	set("long", @LONG
這是一座拱橋，是用青石磚所建造而成的，相當堅固，從拱橋往下望
可看見小烏龜在裡頭探頭探腦的，紅鯉則爭相搶食。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"p8",
  "west" : __DIR__"p6",
  "south" : __DIR__"p11",
]));
        set("light",1);
set("objects",([
   __DIR__"npc/lee2" : 1,
]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
