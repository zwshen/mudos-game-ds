// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ӫ���"NOR);
	set("long", @LONG
���R���ᦷ�M�Ӫ��b���쪺��ǡA�C�T���B�N���@�ʪ������j��C�G
�R�������Ӯg�b�o�G�����Ӫ��W�A�n�����R�ڡC��b�a�W���ۿj���W�A
ť�۳��s�λ�A�A�Q�o�N�O�H�ͤ@�j�֨ƪ��I
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room118",
	    "south": __DIR__"room115",
	    "west" : __DIR__"room112",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

