// Room: /tmr/garea/forest15.c

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
你正走在林中的一條小路，迎面吹來陣陣寒風，往東南不遠處，似乎
有條人工石子路，相比較這頭的爛泥巴路，準好走多了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "southeast" : __DIR__"forest13",
	  "northwest" : __DIR__"forest16",
	]));
	set("outdoors", "forest");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
