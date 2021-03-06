// Room: /u/s/suez/tsing-yu/map_6_5.c

inherit ROOM;

void create()
{
	set("short", "廣場西北角");
	set("long", @LONG
    一條小巷子直直的往西北而去，東南方的廣場中央，依舊人影稀疏，
幾個官兵打扮的坐在附近的屋簷下談天，說些雞毛蒜皮的小事。一些居民
匆匆忙忙的經過，些許和善的居民向你點頭招呼。在這裡的石縫牆腳緩緩
生長著北邊所失去的綠意，不知名的小花正依偎在靜僻的角落，不知以後
會被附近的孩童摘去玩耍，還是成為行人腳下的碎泥。

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_6_6",
  "northwest" : __DIR__"map_5_4",
  "southeast" : __DIR__"map_7_6",
  "south" : __DIR__"map_7_5",
]));

	setup();
	replace_program(ROOM);
}
