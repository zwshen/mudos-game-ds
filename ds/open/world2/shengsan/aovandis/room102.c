// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"������|�}�M��"NOR);
	set("long", @LONG
�o�̬O��|���}�M�СA�P�򳣬O�}�M�ҭn�Ψ쪺���������C�ܦh�f�w
�����g�b�o�̱Ϧ^�@���i�Q���ͩR�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room085",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/doctor1" : 1,
		__DIR__"npc/nurse" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","hospital");	//��|

	setup();
	replace_program(ROOM);
}

