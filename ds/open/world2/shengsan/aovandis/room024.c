// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���Z�j�D"NOR);
	set("long", @LONG
�A�b���Z�}�������Z�j�D�W�A�|�P���ɷ|����������[���Ϯg�X�Ӫ�
ģ���ϥ��A�����B�����B�����κ񪺡C�o���j�D�O��󫰸̪���b��A��
�誽���N�O�諰���F�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room017",
	    "west" : __DIR__"room019",
	    "south": __DIR__"room061",
	    "north": __DIR__"room089",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}