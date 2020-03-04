// Room: /u/t/tmr/area/vroad5.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
你正在一條滿偏僻的街道，路上的村人和四周的房舍稀稀落落，取而
代之的是間關鶯語及翠樹綠林，倒是個不錯的歸隱所在，往北通往一條街
道，往西南穿過一片草叢不遠處可看到一大片空地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"vroad4",
  "southwest" : __DIR__"glade",
]));
	set("outdoors","forest");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
