// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ĥ@�ӵ�"NOR);
	set("long", @LONG
�o�̬O���Z�}�����Ĥ@�ӵ�A�o�̬O�������̼��x���a�褧�@�A�b�o
�}�}�A�@�w�|���ܦh��ì���C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
         //   "east" : __DIR__"room059",
	    "south": __DIR__"room062",
	    "north": __DIR__"room024",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}