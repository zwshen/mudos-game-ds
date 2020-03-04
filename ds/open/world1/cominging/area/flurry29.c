inherit ROOM;

void create()
{
	set("short", "走廊交接處");
	set("long", @LONG
你站在一個走廊通往另一個走廊的地方，在這兒似乎有些陰森森的
感覺，大概是因為跟另一邊的走廊不同的是，這裡的燈光並不怎麼的明
亮，也不怎麼常開，所以人就顯得少了許多，不過因此也比較寧靜。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"flurry28.c",
  "east" : __DIR__"flurry30.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
