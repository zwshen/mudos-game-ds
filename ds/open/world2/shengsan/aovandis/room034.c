// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���Z�Ϧu�ë�"NOR);
	set("long", @LONG
�o�̬O���Z�Ϧu�å𮧤ο줽���a��A���ɦu�í̴N�O�b�t�d������
�w��ί��ǡA�åB�Y�檺�L�o�i�ê��H���i�X�����A�u�í̬��F�O�@���Z
�}���Ө��Ԧ��L�ۡA�ڭ����Ӭ��L�̭P�W�̤j���q�N�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room026",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/guard" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}