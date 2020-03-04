// Room: /u/a/alickyuen/area/dr13.c

inherit ROOM;

void create()
{
	set("short", "STHospitalCorridor");
	set("long", @LONG
筁膚竒筁硂兵ǐ碮非称ǐ玭禘场痜τ㎝
︽痜羪︹常畉τョе竲场眔璶单琿丁
洛ネョぃぶ淮痜秨みパ玭ǐ筁ㄓ螟笵Τぐ或
ㄆ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr14",
  "north" : __DIR__"dr11",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
