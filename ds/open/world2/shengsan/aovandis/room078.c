// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�]�_��"NOR);
	set("long", @LONG
�A�b�@���]�_���̡A�d�l�̦��n�h���Q���_�ۤΦW�Q�˹��~�A���̪�
�~�����|�b�o�R��L�̩ҳ߷R�������B����B�٫������}�G�����~�A����
�c�h�A�ؤ��v���C��W���ӧG�i�P(note)�C
LONG
	);
	set("item_desc", ([
	"note":@NOTE
[1;32m
�G�i�P�W�g��:

		buy       �V����R�F��
		list      ����|�i�D�A�o�̽�Ǥ���
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room012",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss1.c" : 1,
	]));

	set("no_clean_up", 0);
	set("valid_startroom",1);
	set("light", 1);
	set("room_type","sell");	

	setup();
	replace_program(ROOM);
}