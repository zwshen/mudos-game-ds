// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�ʳf���q"NOR);
	set("long", @LONG
�Ҧ��ɻ쪺���ųf�b�o�䳣��o��A�o�̬O�����}���ʪ����g���a�I
�A�ר�O��F����A�H�餧����i�묰�_���C�n�䪺�s���٦��@�y�p����
�����A�����W���Ӥ�������������ѤW�ӤU���ӲӤ��y�o�ަ���ʡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room088",
	    "west" : __DIR__"room099",
            ]));

	set("objects", ([ /* sizeof() == 1 */
//		__DIR__"npc/boss.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}