// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ӫ���"NOR);
	set("long", @LONG
�G�R�������Ӯg�b�o�G�����Ӫ��W�A�U���U�˪��Ӫ����b�A������
�U�F�A�A�ݨ즳�\�h�i�R���p�ͪ��b�䤤���A���֡C��b�a�W���ۿj���W
�Ať�۳��s�λ�A�A�Q�o�N�O�H�ͤ@�j�֨ƪ��I
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room117",
	    "south": __DIR__"room118",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}
