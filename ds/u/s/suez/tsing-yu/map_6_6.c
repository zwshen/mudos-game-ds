// Room: /u/s/suez/tsing-yu/map_6_6.c

inherit ROOM;

void create()
{
	set("short", "廣場北");
	set("long", @LONG
    由你背後吹來強烈的狂風，兩旁的幾以光禿的樹也被風吹的不停晃動
，這道風將你身邊的一切吹向你面前廣大的空地，幾個行人低著頭快步走
過你身旁，當他們的人影消失在其他的巷道內，你有一種被遺棄的感覺。
回想峽道外如詩如畫的山景和眼前延伸到遠方的石板地，一種強烈的對比
，你覺得自己的內心被什麼東西打了一下。

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 6 */
  "southwest" : __DIR__"map_7_5",
  "east" : __DIR__"map_6_7",
  "north" : __DIR__"map_5_6",
  "west" : __DIR__"map_6_5",
  "southeast" : __DIR__"map_7_7",
  "south" : __DIR__"map_7_6",
]));

	setup();
	replace_program(ROOM);
}
