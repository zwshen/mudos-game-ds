// Room: /tmr/future/hunter_forest/forest4.c

inherit ROOM;

void create()
{
	set("short", "森林小路");
	set("long", @LONG
你正走在森林中的一條小路，生長良好的樹木，盡是繁密的樹枝、樹
葉，樹與樹之間，交互勾肩，遮蔽了大半部分照射下來的陽光，使得這條
小路顯得陰暗許多。在你的西邊有條小徑可以通到一棵大亞連樹前。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"forest8",
	  "east" : __DIR__"forest2.c",
	]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("world", "future");

	setup();
	replace_program(ROOM);
}
