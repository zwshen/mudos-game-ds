// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�e�s�����D"NOR);
	set("long", @LONG
�A�b�@�ӫn�_���V���e�s���D�W�A���D�W�^�ۦU�ج��R���[���A�ұ�
�X�����˼˦����H��i�ҫ�A���A���o���ٹī��������R�A���_�����i��
�F���������ߦa�a�A���n�����O�������������C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "south": __DIR__"room008",
	    "north": __DIR__"room006",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}