// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "湖邊");
	set("long", @LONG
一排的情人椅座落在湖岸上，在椅子旁還有一排的柳樹，這裡是熱戀
男女最喜歡來的地點之一，因為這裡的氣氛很羅曼蒂克。不時間你可以觀
察到湖面受到為風擾動而成的漣漪。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out048",
	    "north": __DIR__"out040",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}