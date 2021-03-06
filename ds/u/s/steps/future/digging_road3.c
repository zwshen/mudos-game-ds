// Room: /future/area/digging_road3.c

inherit ROOM;

void create()
{
	set("short", "礦區道路");
	set("long", @LONG
你正走在一條礦區的道路，道路兩旁是數棟七至八層樓高的鐵類合金
式建築物，由於日曬雨淋的關係，徵見斑駮，為此礦區的礦工所居住的地
方，往東循著道路走下去更則更深入住宅區，往西走去可到達掌管此區煤
鐵事宜的工廠。
LONG
	);
	set("world", "future");
	set("outdoors","desert");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"digging_road2",
	  "east" : __DIR__"digging_street1",
	]));

	setup();
	replace_program(ROOM);
}
