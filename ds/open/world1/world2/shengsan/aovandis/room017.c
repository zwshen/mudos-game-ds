// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���߼s���谼"NOR);
	set("long", @LONG
�n�h���a���e�������b�o�Ӽs�����ʡA���ɧA�|�ݨ�ൣ�b�H�s���b
�]���A�A���ɧA�|�ݨ쭱�a�ƽ]���p���b�A�S�ޡA���ɧA�S�|�ݨ���ʤ�
�����Q��Եۤ�b���ȤW���ۡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room001",
	    "west" : __DIR__"room024",
	    "south": __DIR__"room059",
	    "north": __DIR__"room057",
            ]));
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/bird2" : 3,
        ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}