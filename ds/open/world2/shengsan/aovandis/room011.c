// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�}���j�D"NOR);
	set("long", @LONG
�A�b���Z�}�����}���j�D�W�A�o���j�D�O��󫰸̪��F�b��A���F��
���N�O�F�����F�C�M�ӡA�A�ݨ�n��n���x���A�n���O�ө���a�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room012",
	    "west" : __DIR__"room010",
	    "south": __DIR__"room067",
	    "north": __DIR__"room091",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}