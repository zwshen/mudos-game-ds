// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"����"NOR);
	set("long", @LONG
�o���\�]�ۤ@�륫���һݪ��a��A�èS������S�O���a��C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room082",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}