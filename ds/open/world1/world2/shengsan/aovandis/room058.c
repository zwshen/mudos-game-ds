// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���߼s���F�_��"NOR);
	set("long", @LONG
�A�b�s�����F�_��A�a�W�^�ۦU�ج��R���[���A�ұƥX�����˼˦���
�H��i�ҫ�A���A���o���ٹī��������R�C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room042",
	    "south": __DIR__"room010",
            ]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/sergeant" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}