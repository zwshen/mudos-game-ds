// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�}���j�D"NOR);
	set("long", @LONG
�A�b���Z�}�����}���j�D�W�A���D��Ǫ��Ƥ����]�O�Ѭ��R���[����
�䦨�A�Ƥ����\�W���Ϯ׬O�@�������|��ൣ�mø�[�����ʪ��ѥ[�@�~�A
�o�w�g�O���Z�}�����@�j�S��F�o���j�D�O��󫰸̪��F�b��A���F����
�N�O�F�����F�A���n��N�O�u�ëǤF�C
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room016",
	    "west" : __DIR__"room014",
	    "south": __DIR__"room035",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}