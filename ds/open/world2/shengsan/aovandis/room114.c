// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ӫ���"NOR);
	set("long", @LONG
���R���ᦷ�M�Ӫ��b���쪺��ǡA�C�T���B�N���@�ʪ������j��C�G
�R�������Ӯg�b�o�G�����Ӫ��W�C�w�R���Ӫ���O�����̺}�G������A
�����̳��Q�ζ��v���l�ӳo�̴����B�A�ȷȳ��A����A���P�@�U���^��
�����C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "north": __DIR__"room112",
            "east" : __DIR__"room115",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bug0.c" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

