// Modify with AreaMaker1.0
// Room11.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
一走進這裡北方的高山立刻映入眼簾。四周到處都是大樹，滿地
的雜草和枯葉，因為這裡的樹葉濃密，所以有些潮濕。你發現一些少
見的蕨類也生長於此。附近還不時傳出鳥獸的鳴叫聲。
LONG
	);
	set("exits", ([
		"east": __DIR__"room12",
		"west": SHENGSAN2"aovandis/out064",
		"south": __DIR__"room21",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

