// 而瓆吹

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"皊"NOR);
	set("long", @LONG
程Τ皊常琌硂艭硑Τ砛常琌环眖紏τㄓ
鲤Τボ礟(note)
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room068",
	    "down" : __DIR__"room106",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

