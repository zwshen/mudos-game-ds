// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���Z�j�D"NOR);
	set("long", @LONG
�|�P���ɷ|����������[���Ϯg�X�Ӫ�ģ���ϥ��A�����B�����B����
�κ񪺡C�b���Z�}�������Z�j�D�W�A�A�ݨ�F�¾몺�����b������V�A��
�۩I�A�o���j�D�O��󫰸̪���b��A���誽���N�O�諰���F�C
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room021",
	    "west" : __DIR__"room033",
	    "south": __DIR__"room034",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}