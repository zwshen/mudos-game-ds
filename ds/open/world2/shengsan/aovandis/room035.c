// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�}���Ϧu�ë�"NOR);
	set("long", @LONG
�o�Ӥp�ж��N�O�u�å𮧤ο줽���a��A�u�í̬��F�O�@���Z�}����
���Ԧ��L�ۡA�ڭ����Ӭ��L�̭P�W�̤j���q�N�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room015",
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