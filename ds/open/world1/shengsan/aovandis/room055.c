// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"民房"NOR);
	set("long", @LONG
這裡擺設著一般市民所需的家具，並沒有什麼特別的地方。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room082",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}