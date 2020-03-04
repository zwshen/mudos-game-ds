// Room: /u/m/mulder/area/inn.c

inherit ROOM;

void create()
{
	set("short", "新彼得旅店");
	set("long", @LONG
這是新彼得旅店，你可看到這裏有很多人出出入入．在這裏
你可以住宿或是保給一下或是在這裏週到逛．這裏你可以向服務
生買食物或是食水．
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "start" : __DIR__"road1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/waiter.c" : 1,
]));
	set("no_fight", 1);
	set("no_clean_up", 0);
set("light",1);

	setup();
	replace_program(ROOM);
}
