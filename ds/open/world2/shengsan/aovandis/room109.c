// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�\\�U���]�["NOR);
	set("long", @LONG
�o���\�U�W�Ҭ۷��j�A�\�U�����ȤH��ö�����C��������^�R����
���A�n���H�K�ߡC
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room107",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

