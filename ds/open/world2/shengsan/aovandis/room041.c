// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�u�ö��줽��"NOR);
	set("long", @LONG
�A�Pı���غ�i����^�b�o�Ӥp�ж��̡A���ѦۥD���A�]�����Fĵı
�߲`�Ȧۤv�|��������ƨӡC
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room040",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/guard" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}