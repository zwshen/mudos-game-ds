// Room: /u/s/sub/area/village/vi03.c

inherit ROOM;

void create()
{
	set("short", "碎石小路");
	set("long", @LONG
這裡的地面是由碎石所舖成的，相當的美觀。東邊不遠處還可以看到
幾間小房子，還不時冒出縷縷的炊煙，和藍天交織成一幅美麗的畫面，真
是每不勝收。可以看到有些居民在街上走動，到處都充滿了熱鬧的氣氛。
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 3);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"vi02",
  "east" : __DIR__"vi04.c",
]));

	setup();
	replace_program(ROOM);
}
