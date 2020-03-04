// Room: /open/world1/tmr/bagi/area/2f/3f-1.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
你正走在一條密不通風的祕道內，在這裡空氣好像是靜止的一樣，完
全沒有流動的跡像，悶的人都出一身汗了，東邊似乎傳來野獸的聲響。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"3f-2",
  "west" : __DIR__"3f",
]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
