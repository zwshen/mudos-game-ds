// Room: /u/s/sub/area/village/vi05.c

inherit ROOM;

void create()
{
	set("short", "碎石小路");
	set("long", @LONG
這是一條貫穿小村莊的南北向道路。兩側不時地傳來敲打金屬的撞擊
聲，使寧靜的街道上多了些許的喧鬧。不禁讓人感到好奇，難道這寧靜的
小村莊還需要裝備？西邊是一間武器店，東邊是一間防具店。
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"vi09",
  "north" : __DIR__"vi06",
  "west" : __DIR__"wproom",
  "south" : __DIR__"vi04",
]));

	setup();
	replace_program(ROOM);
}
