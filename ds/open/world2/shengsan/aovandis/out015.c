// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯城牆外");
	set("long", @LONG
青青的茵草長在奧凡迪斯的城牆外，這個城牆已經有幾千年的歷史了
。有些遊客會在這裡拍照留念，也有些考古學家在這邊觀察城牆，還有一
些建築師在這邊研究城牆的結構。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out022",
	    "north": __DIR__"out011",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}