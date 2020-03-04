// Room: /u/s/sub/workroom.c

inherit ROOM;

void create()
{
	set("short", "小蝦子發呆房");
	set("long", @LONG
  ，  。  、  ？  【  】  『  』  ！
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 8 */
  "ant" : __DIR__"area/ant_hill/map_1_15.c",
"village" : __DIR__"area/village/inn.c",
  "hall" : "/d/wiz/hall1.c",
  "valley" : __DIR__"area/valley/map_7_3.c",
  "past" : "/open/world1/tmr/area/hotel.c",
  "nye" : "/u/n/nye/workroom.c",
  "wil" : "/u/w/wilfred/workroom.c",
]));
	set("current_light", 12);

	setup();
	replace_program(ROOM);
}
