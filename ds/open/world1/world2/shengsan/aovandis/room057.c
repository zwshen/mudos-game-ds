// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���߼s����_��"NOR);
	set("long", @LONG
�A�b�s������_��A�a�W�^�ۦU�ج��R���[���A�ұƥX�����˼˦���
�H��i�ҫ�A���A���o���ٹī��������R�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room042",
	    "south": __DIR__"room017",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}