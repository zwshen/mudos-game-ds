// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�F������"NOR);
	set("long", @LONG
�o�̬O���Z�}�����F�������A�¾몺�����`�`�b�o�̶i�i�X�X�A�n��
�֡A�]�n�۵M�C�o�����M�O�����A������׫o�]�����L�������Ӫ���
��A�Ʀܦ��L���ӵL���ΡC�p�G�A�n�X��(out)�A�O�ѤF��u�å��۩I��C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room015",
	    "out"  : "/open/world2/mainland1/map_22_28",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/gateguard" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
