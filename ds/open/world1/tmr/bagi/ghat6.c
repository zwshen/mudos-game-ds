// Room: /open/world1/tmr/bagi/ghat6.c

inherit ROOM;

void create()
{
	set("short", "冰湖前");
	set("long", @LONG
在你面前是座大冰湖，高山上寒冷的氣候使得湖面結了厚厚地的一層
冰，湖心中央的冰層不時透出銀藍交加的光芒，似乎使得周圍的氣溫又降
低了許多，你已不知不覺得縮起身，發起抖來。
LONG
	);
	set("world", "past");
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"ghat7",
  "southwest" : __DIR__"ghat4",
  "northwest" : __DIR__"ghat8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
