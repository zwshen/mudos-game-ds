// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
有許多大大小小不同種類的樹木生長在這邊，有一些飛鳥的鳥巢就築
在大樹的樹枝之上，往東有一條進入樹林裡的便道，應該是前人所留下的
，這裡是奧凡迪斯的郊區，在附近有一條通往奧凡迪斯的道路。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out037",
	    "north": __DIR__"out029",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}