// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���Z�}��������"NOR);
	set("long", @LONG
�o�̬O���Z�}�����������A�����Ϋ��𳣰��o���ӹ��ܡA�ݰ_�Ӥw�g
�S������Z�����o�̳y���}�a�F�A���D�Ψ�ǤW�^�ۦU�ج��R���[���A
�ұƥX�����˼˦����H��i�ҫ�C�b�����ǧA�ݨ�F�@����P(plaque)�C
�p�G�A�n�X��(out)�A�O�ѤF��u�å��۩I��C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "north": __DIR__"room008",
	    "out":  "/open/world2/mainland1/map_23_27",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/gateguard" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	set("item_desc", ([
		"plaque":@NOTE
��P�W�g��:
		[1;32;44m������������������������������������������[m
		[1;32;44m��      ��      �Z      �}      ��      ��[m
		[1;32;44m������������������������������������������[m

NOTE
     ]) );

	setup();
	replace_program(ROOM);
}
