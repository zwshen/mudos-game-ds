// Room: /open/world1/tmr/bagi/ghat9.c

inherit ROOM;

void create()
{
	set("short", "冷月池前");
	set("long", @LONG
你站在冷月池的池邊，因此處比其他岸邊更為突出，所以自然形成了
一處半島的地方。在此處你可以看到湖心中央的冰層泛起深藍色的光，在
你仔細觀察下，你見到一柱狀物體由湖底直達湖面，而此柱柱頂有一鼎，
不知有什麼用途。此柱只是由於被冰層所圍繞著，所以在遠處時看不見此
柱。
LONG
	);
	set("world", "past");
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ghat8",
  "east" : __DIR__"ghat7",
]));
	set("no_clean_up", 0);
    set("objects",([
     __DIR__"npc/cmoon2":1,
    ]) );

	setup();
	replace_program(ROOM);
}
