// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���D"NOR);
	set("long", @LONG
�A�b�@�ӧN�M�����D�W�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"room036",
	    "south": __DIR__"room038",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}