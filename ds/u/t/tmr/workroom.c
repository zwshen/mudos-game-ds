// Room: /u/t/tmr/workroom.c

inherit ROOM;

void create()
{
	set("short", "奇家大門");
	set("long", @LONG
這是奇家大門，往南是滄縣城門，如不急著趕路，倒不仿進去.
奇家看看，或者可以去滄縣看看「朝天湖」這個名勝，往東可到一
個小鎮。
LONG
	);
	set("valid_startroom", "1");
	set("outdoors", "lands");
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 4 */
  "past" : "/open/world1/tmr/area/hotel",
  "enter" : __DIR__"room/square",
  "wiz" : "/d/wiz/hall1",
  "future" : "/open/world3/tmr/basic/hotel",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
