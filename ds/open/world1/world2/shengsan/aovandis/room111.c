// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ӫ���"NOR);
	set("long", @LONG
���R���ᦷ�M�Ӫ��b���쪺��ǡA�C�T���B�N���@�ʪ������j��C�G
�R�������Ӯg�b�o�G�����Ӫ��W�A�n�����R�ڡC�U���U�˪��Ӫ����b�A
�������U�F�A�A�ݨ즳�\�h�i�R���p�ͪ��b�䤤���A���֡C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "north": __DIR__"room050",
            "east" : __DIR__"room112",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

