// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ӫ���"NOR);
	set("long", @LONG
���زM�n���������A���W���F�L�ӡA�P�򦳦n�h�_�Ყ��ΦU�ت��i
�R�p���ΡC�A���O�b���Z�}���ۦW���Ӫ���̡C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "north": __DIR__"room117",
	    "west" : __DIR__"room118",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

