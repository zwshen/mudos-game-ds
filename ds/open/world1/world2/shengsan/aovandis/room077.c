// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�q�����"NOR);
	set("long", @LONG
�ﭱ�ӨӪ��N�O�@�i�i�K�b���f�������A�����d�W�\�ۤ@�|�|���q��
������A�����d�����C�ۦU�����q���ӫ~�C�A�ݨ�X�ӤH���ۤ@�Ӥp���
�A���G���b�Q�׻����C�o�̬O�������W���q������A�b�o�̧A�i�H�R��A
�Q�n������޹q�����~�C��W�ٱ��ۤ@�ӧi�ܵP(sign)�C

LONG
	);
	set("item_desc", (["sign":@NOTE
[1;36m
�G�i�P�W�g��:
[1;32m
		buy       �V����R�F��
		list      ����|�i�D�A�o�̽�Ǥ���
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room062",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss5.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","sell");
	setup();
	replace_program(ROOM);
}