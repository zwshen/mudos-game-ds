// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���D"NOR);
	set("long", @LONG
�A���b�@�����b�����D�W�C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room050",
	    "west" : __DIR__"room048",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}