// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�W�h���D"NOR);
	set("long", @LONG
�A���b�@�ƱƩ��_�ӤW���۶����W�A�۶��W�^�ۦU�ج��R���[���A��
�ƥX�����˼˦����H��i�ҫ�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room055",
	    "west" : __DIR__"room094",
	    "south": __DIR__"room088",
	    "north": __DIR__"room052",
            ]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/patrol" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}