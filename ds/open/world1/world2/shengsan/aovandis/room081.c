// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�ѥ]��"NOR);
	set("long", @LONG
�p�G�A�n�Y�Y�̨�S�⪺�ѥ]�A����A�ӹ�a��F�C�o�O�@���H�зN
�ά������Ӫ��ѥ]���A�Ʀn��b�A�ӥB�����]�۷��K�y�C���̪��~����
�|�b�o�R�L�̷R�Y���ѥ]�A�C���y�ͮɡA�o�̩Ұ��X���J�|�]�O�L�̪�
�̷R�C��W���ۤ@�ӧi��(sign)�C
LONG
	);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss2.c" : 1,
	]));

	set("item_desc", (["sign":@NOTE
[1;32m
�G�i�P�W�g��:

		buy       �V����R�F��
		list      ����|�i�D�A�o�̽�Ǥ���
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"room070",
            ]));

	set("no_clean_up", 0);
	set("valid_startroom",1);
	set("light", 1);
	set("room_type","sell");	// �ө�(�u��R�F��)

	setup();
	replace_program(ROOM);
}