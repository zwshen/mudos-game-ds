// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�ǳN���D"NOR);
	set("long", @LONG
�A���b�@�����ǳN�𮧪����D�W�C���W���A�i�H��F���F�[�j�Ǫ��J
�f�C�A�i�H�ݨ�@�ӵP�l(sign)���ߦb�J�f�B�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room053",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("item_desc", (["sign":@NOTE

		     ��������      �\
	    �\       �x �� �x
	             �x �� �x            �\
	�\         ���� �� ����
		�\ �x�x �� �x�x
		   �x�x �� �x�x�\
		   �x��������x
		 �~�r��    �~�r��   �\
	     �ʡ����w���ʡ����w���ʡ�
	         ��       �\    ��      �\
NOTE
        ]) );

	setup();
	replace_program(ROOM);
}