// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���D"NOR);
	set("long", @LONG
�b�o���N�M�����D�W�A�A�ݨ�����W������A�شӵۦU���U�˪���
���ý��A�L�̪��D�H��Ԫ�����I�Τ~���o�몺���H�C�ӳo�����D�o�A��
���H�g�L�A�]�\�O�]���o�����D�������䪺���Y�a�C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room037",
	    "west" : __DIR__"room008",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}