// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
這裡的坡度有點傾斜，是由北往南升高。不過這裡的樹木仍然很多，
有高的有矮的，有粗壯的有瘦小的。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out062",
	    "north": __DIR__"out052",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}