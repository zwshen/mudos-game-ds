// Room: /open/world1/tmr/north_bar/town16.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－巷子");
	set("long", @LONG
你正走在一處巷子裡，兩旁房屋的牆壁，都是由磚塊組
成。偶爾會有幾個村裡的小孩呼嘯而過。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"town14",
  "northwest" : __DIR__"town17",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
