// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ĥ@�ӵ�"NOR);
	set("long", @LONG
�o�̬O���Z�}�����Ĥ@�ӵ�A�o�̬O�������̼��x���a�褧�@�A�b�o
�}�}�A�@�w�|���ܦh��ì���C����O¾�~���ЩҡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room066",
	    "west" : __DIR__"room076",
	    "north": __DIR__"room063",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}