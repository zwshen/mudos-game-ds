// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"盜賊工會內室"NOR);
	set("long", @LONG
這裡是高級盜賊練習技能的房間，有位盜賊導師在這教導學生盜賊技能。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room087",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}