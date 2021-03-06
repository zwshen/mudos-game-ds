// Room: /u/l/lestia/area/sn11.c

inherit ROOM;

void create()
{
	set("short", "北方大森林");
	set("long", @LONG

一片片樹葉在你頭上飛舞著，些許的陽光藉著葉與葉中的縫隙穿射過來
，使得地上黑色的樹蔭浮現著點點光粒，傳說中神秘的靈幻教便是隱藏於這
片廣大的森林之中，許多有心學習道術的人們都嚮往前往神秘的聖地，但似
乎除了靈幻教徒之外，並沒有人能夠破解進入聖地的方法。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sn10",
  "south" : __DIR__"sn12",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
