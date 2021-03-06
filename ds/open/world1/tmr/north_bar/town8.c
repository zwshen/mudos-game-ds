// Room: /open/world1/tmr/north_bar/town8.c

inherit ROOM;

void create()
{
	set("short", "北蠻村-石壁道路");
	set("long", @LONG
這裡前面有一條入直通往前方，但兩旁的石壁高聳入天，使
得這條小路看起來十分的狹窄，而且這裡附近也開始沒有什麼行
人，加上風又吹的大，心裡不禁有點毛毛的。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town7",
  "north" : __DIR__"town9",
]));
	set("no_clean_up", 0);
	set("shrot", "北蠻村-石壁道路");
	set("outdoors", "land");
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
