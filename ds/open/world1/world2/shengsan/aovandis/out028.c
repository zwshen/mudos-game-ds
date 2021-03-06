// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
有許多的小黃花在這邊生長成一片，許多的蝴蝶和蜜蜂出現在這邊飛
舞覓食，幾塊大石頭被放在這片小黃花之中。你聽到北方傳來開車的聲音
，好像北方是一條道路。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out029",
	    "west" : __DIR__"out027",
	    "north": __DIR__"out020",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}