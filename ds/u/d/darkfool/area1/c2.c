// Room: /u/d/darkfool/area1/c2.c

inherit ROOM;

void create()
{
	set("short", "廣場東側");
	set("long", @LONG
你往東走了幾步，來到了一根大圓柱前，你伸手撫摸它的表面，發覺
質地十分的滑潤。你又仰頭看了一下，圓柱上鑲著一顆寶石樣的東西，不
知有何作用。另外值得注意的地方是有幾個圖形繞著圓柱轉了一圈，而每
個圖形下都有著圓盤形的凹槽。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"c1",
]));

	setup();
	replace_program(ROOM);
}
