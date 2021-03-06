// Room: /u/s/suez/tsing-yu/map_7_6.c

inherit ROOM;

void create()
{
	set("short", "大廣場");
	set("long", @LONG
    你一踏入這裡，就被這裡的空曠給嚇到。龐大有如一個小村的空地上
，僅佇立著一塊琢磨已久的玉石，以及一口不知為何在此的枯井。聽說在
清晨以及深夜，會由枯井中傳出喊殺聲，壯烈的程度好似又讓人回到古時
的戰場，加上由峽道吹來的凜冽山風，站在這裡的你，覺得孤獨､疏離､
獨自徘徊在歷史的洪流之中，看著一切生生死死､是是非非，你突然覺得
好像看清人類的一切，卻又抓不住自我存在的感覺。看著獨立在眼前的古
玉，你的心中不禁一陣酸楚。

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 8 */
  "southwest" : __DIR__"map_8_5",
  "east" : __DIR__"map_7_7",
  "north" : __DIR__"map_6_6",
  "northwest" : __DIR__"map_6_5",
  "west" : __DIR__"map_7_5",
  "southeast" : __DIR__"map_8_7",
  "south" : __DIR__"map_8_6",
  "northeast" : __DIR__"map_6_7",
]));

	setup();
	replace_program(ROOM);
}
