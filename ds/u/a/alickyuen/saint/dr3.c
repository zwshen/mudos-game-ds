// Room: /u/a/alickyuen/area/dr3.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Door");
	set("long", @LONG
在這條走廊，你能見到一個電子顯示板，醫院有什麼大小事情或想查
詢入院明單也可以從這看到。往北便是醫院１樓的大堂。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dr4",
  "out" : __DIR__"dr2",
]));
set("objects", ([
__DIR__"obj/board.c" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}
