// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"������|"NOR);
	set("long", @LONG
���Z�}�����̦��W����|�N�ݳo�̤F�A��|�����̱M�~����v�n�E�A
�٦��̷s�������������b��|�̡C�A�ݨ�ܦh�D�E���f�w���b�������ԡC
������ҬO�|���ҷ��O���ʪ��A�ҥH�A�|�ݨ줣�֪����Ӫ����t�Ϊ��\
�����|�U�Ӧa��C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "south": __DIR__"room048",
	    "north": __DIR__"room102",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/doctor0" : 1,
		__DIR__"npc/nurse" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","hospital");	//��|

	setup();
	replace_program(ROOM);
}