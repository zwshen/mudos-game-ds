// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�s��u�|"NOR);
	set("long", @LONG
�o�̬O���ŵs��m�ߧޯ઺�ж��A����s��ɮv�b�o�оɾǥ͵s��ޯ�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room087",
            ]));
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/thief_master" : 1,
        ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}