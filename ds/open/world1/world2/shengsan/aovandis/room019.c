// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���Z�j�D"NOR);
	set("long", @LONG
�A�b���Z�}�������Z�j�D�W�A�o���j�D�O��󫰸̪���b��A���誽
���N�O�諰���F�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room024",
	    "west" : __DIR__"room020",
	    "south": __DIR__"room073",
	    "north": __DIR__"room086",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}