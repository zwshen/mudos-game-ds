// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "郊區小路");
	set("long", @LONG
這裡是奧凡迪斯的郊區小路，兩旁是排水溝以及依稀的棕梠樹或是一
些小花及小草。路上的行人並不會很多，而汽車也是稀稀落落的。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out024",
	    "south": __DIR__"out032",
	    "north": __DIR__"out017",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}