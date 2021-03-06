// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "湖邊樹林");
	set("long", @LONG
空氣突然涼爽了起來，微微的清風迎面向你吹來，你看到西南方的遠
處有一座碧綠的湖泊。泥土與落葉相相私混在一起，成為你所見的地面。
這裡是奧凡迪斯的郊區，你可以到處走走找到通往奧凡迪斯的道路。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out049",
	    "south": __DIR__"out055",
	    "north": __DIR__"out041",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}