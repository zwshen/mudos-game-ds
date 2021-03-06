// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "商業道路");
	set("long", @LONG
寬敞的商業道路裡，汽車、機車、大貨車或是客運的蹤跡不斷，因為
這裡是個大轉彎，所以有時候會在新聞中看到這個路段出車禍的報導，你
不得不小心，免得造成一輩子的遺憾。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out019",
	    "south": __DIR__"out026",
            ]));

	set("light",1);
	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}