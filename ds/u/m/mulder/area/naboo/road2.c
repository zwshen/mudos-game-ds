// Room: /u/s/sonicct/area/road2.c

inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
這裡有很多人由南面的太空船站湧上北面的市中心，十分擠
迫。你發現了北面五光十色的燈光，就知道這裡就是Naboo的市中
心--最繁華的地區。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road20",
  "north" : __DIR__"road3",
//  "west" : __DIR__"road13",
  "south" : __DIR__"road1",
]));
		 set("objects",([
  __DIR__"npc/citizen":1,
 ]));

	set("outdoors","road");
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}
