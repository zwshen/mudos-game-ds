// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�s�a�a�U��"NOR);
	set("long", @LONG
�o�̬O�s�����a�U�ǡA���ؾK�H�������������V�A����y���A������
�ΡC���ܦh�˺��W�Q�s������l�s��b�o�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "up"   : __DIR__"room120",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

