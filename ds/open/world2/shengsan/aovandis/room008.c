// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�e�s�����D"NOR);
	set("long", @LONG
�A�b�@�Ӽe�s���D�W�A���D�W�^�ۦU�ج��R���[���A�ұƥX�����˼�
�����H��i�ҫ�A���A���o���ٹī��������R�A���_�����i��F��������
�ߦa�a�A���n�����O�������������A�F��謰�u�ê��줽�ǡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room036",
	    "west" : __DIR__"room039",
	    "south": __DIR__"room009",
	    "north": __DIR__"room007",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}