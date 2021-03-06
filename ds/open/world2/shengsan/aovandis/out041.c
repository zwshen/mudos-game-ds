// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
樹林內的樹都拼命得向上生長，枝頭的樹葉茂盛的長著，使得樹下是
一片的涼爽，大樹與大樹之間有時會有松鼠或其它的生物跳躍期間，樹幹
上可以看到覆蓋著一層青苔。青苔上還有螞蟻在辛勤的工作著。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out042",
	    "south": __DIR__"out050",
	    "north": __DIR__"out037",
            ]));

	set("outdoors","forest");	// 樹林
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}