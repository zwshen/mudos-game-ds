// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ĥ@�ӵ�"NOR);
	set("long", @LONG
�o�̬O���Z�}�����Ĥ@�ӵ�A�o�̬O�������̼��x���a�褧�@�A�b�o
�}�}�A�@�w�|���ܦh��ì���C����O�B�ä��ЩҡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room065",
	    "west" : __DIR__"room075",
	    "south": __DIR__"room064",
	    "north": __DIR__"room062",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/citizen1" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}