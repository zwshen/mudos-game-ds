// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ӫ���"NOR);
	set("long", @LONG
�w�R���Ӫ���O�����̺}�G������A�����̳��Q�ζ��v���l�ӳo�̴���
�B�A�ȷȳ��A����A���P�@�U���^�������C�ܦh�ɭԤ]�|���������b�Ψm
�c�W���ͩݽװ_�ӡA�H��o�v���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"room119",
	    "west" : __DIR__"room116",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird1.c" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

