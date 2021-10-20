// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "山麓");
	set("long", @LONG
地勢有點崎嶇不平，不太好走的樣子。幾棵大樹仍然在這邊盤據著山
麓，樹上還有幾個樹洞，不知道是什麼動物住在裡面？偶而你會看到民航
機從這上頭飛過。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out061",
	    "west" : __DIR__"out059",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}