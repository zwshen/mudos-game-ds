// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
這裡的微風相當的清爽，有許多的小碎石及一些鬼針草在地上，幾棵
的小樹生長在這邊，天上的白雲似乎正在對你招手。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out047",
	    "north": __DIR__"out035",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}