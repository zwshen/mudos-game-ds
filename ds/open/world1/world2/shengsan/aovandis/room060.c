// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�u�ö��`�q�O�줽��"NOR);
	set("long", @LONG
�o�̬O�u�ö��`�q�O�ȯS���줽�ǡA��W���U�ت��M�C�A�C���M�C��
�O��~���@�A���A�]�Q�֦����̡C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room067",
	    "north": __DIR__"room010",
            ]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/art" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}