// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�ǳN���D"NOR);
	set("long", @LONG
�A���b�@�����ǳN�𮧪����D�W�A�o���j�D����ǬO���H���Ѫ��j��
�A���ɷ|������b�o���X���b�a�����W�C���誽���i�H��F���F�[�ǰ|�C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room052",
	    "west" : __DIR__"room054",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}