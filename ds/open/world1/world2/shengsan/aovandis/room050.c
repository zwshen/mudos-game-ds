// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ӫ���J�f"NOR);
	set("long", @LONG
���زM�n���������A���W���F�L�ӡA�P�򦳦n�h�_�Ყ��ΦU�ت��i
�R�p���ΡC�A���O�b���Z�}���ۦW���Ӫ���̡C
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room110",
	    "west" : __DIR__"room049",
	    "south": __DIR__"room111",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}