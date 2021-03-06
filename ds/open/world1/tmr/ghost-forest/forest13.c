// Room: /open/world1/tmr/ghost-forest/forest13.c

inherit ROOM;

void create()
{
	set("short", "石子路");
	set("long", @LONG
你正在一條由人工鋪成的石子路上，道路兩旁種滿了兩排罕見的白菊
，往東邊林蔭深處望去可瞧見有座小祠，往南不遠處，瀰漫了陣陣白茫茫
的霧氣，越是過去，似乎霧氣越盛。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"shrine.c",
  "northwest" : __DIR__"forest15",
  "southwest" : __DIR__"forest11",
]));
	set("outdoors", "forest");
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
