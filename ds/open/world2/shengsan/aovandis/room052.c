// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�ǳN���D"NOR);
	set("long", @LONG
�o�O���L�����D���e�飼�D�A���ɳo���������j�D�|�ɰ_�@�h������
�����A�ϱo�o���ǳN�𮧪����D�W�W�K�X�����a�g�����C�_�観�Ӥp�����A
���誽���i�H��F���F�[�ǰ|�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room051",
	    "west" : __DIR__"room053",
	    "south": __DIR__"room082",
	    "north": __DIR__"room083",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/guard" : 2,
		__DIR__"npc/citizen2" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}