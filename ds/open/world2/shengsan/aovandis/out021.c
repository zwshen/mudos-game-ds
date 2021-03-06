// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
這裡生意盎然，微微的清風從南方吹拂而來，青草及小樹在這邊到處
生長著，有時你會踏到破爛的瓦片而發出嘎嘎的聲音，一兩片枯葉偶而也
會在你身邊飛過。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out022",
	    "south": __DIR__"out030",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}