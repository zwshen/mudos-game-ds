// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�A����~��"NOR);
	set("long", @LONG
�o���W���ۤ@��ӼүS��A������R���A�ˡA���۫G�R�����~�C�@��
���������b�Ѫ�üY�a���Ȥ���P�������Ҧ��A����~�C�������Ѫ�O�Q
�ۤ@�ӭӰ{�G�������A�����C��A���C��A�����ⵥ���C
��W���ӵP�l(sign)
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room101",
	    "west" : __DIR__"room090",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss4.c" : 1,
	]));

	set("item_desc", (["sign":@NOTE
[1;32m
�G�i�P�W�g��:
[1;33m
		buy       �V����R�F��
		list      ����|�i�D�A�o�̽�Ǥ���

[m
NOTE
        ]) );

	set("no_clean_up", 0);
	set("valid_startroom",1);
	set("light", 1);
	set("room_type","sell");	// �ө�(�u��R�F��)

	setup();
	replace_program(ROOM);
}