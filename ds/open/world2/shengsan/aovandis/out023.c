// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "郊區農田");
	set("long", @LONG
這裡有一格一格田埂所圍起來的農田，裡面種的是金黃色的稻米，有
一個農夫正在使用收割機收割稻子，農夫臉上一臉愉快的面容，想必這次
都收割是個大豐收。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out024",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}