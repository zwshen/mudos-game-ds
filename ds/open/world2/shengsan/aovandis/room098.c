// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"����U�ݤ��q�|ĳ��"NOR);
	set("long", @LONG
�|ĳ�Ǥ����Ӫ������|ĳ��A��W�����J���A�b�����٦��ӲG����v
���C�a�O�O�j�z�۩M�[���V�M�Ӧ����S��ۧ��ҳy���A�q���~�g�i������
�Ӧb�a�W��~��ģ���C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room086",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}