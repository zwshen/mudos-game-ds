// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�ĤG�ӵ�"NOR);
	set("long", @LONG
�o�̬O���Z�}�����ĤG�ӵ�A�o�̬O�������̼��x���a�褧�@�A�b�o
�}�}�A�@�w�|���ܦh��ì���C
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room070",
	    "west" : __DIR__"room005",
	    "north": __DIR__"room071",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}