// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ӫ���"NOR);
	set("long", @LONG
�U���U�˪��Ӫ����b�A�������U�F�A�A�ݨ즳�\�h�i�R���p�ͪ��b��
�����A���֡C�G�R�������Ӯg�b�o�G�����Ӫ��W�A�n�����R�ڡC
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "north": __DIR__"room113",
	    "west" : __DIR__"room114",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bug1.c" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

