// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ӫ���"NOR);
	set("long", @LONG
��ö�������C�Ȧb�o�[��o�̪��@��@��A���ɧA�|�ݨ�ĵ����^�x
�n��������A���R���ᦷ�M�Ӫ��b���쪺��ǡA�C�T���B�N���@�ʪ�����
�j��C�G�R�������Ӯg�b�o�G�����Ӫ��W�A�n�����R�ڡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"room112",
	    "west" : __DIR__"room050",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

