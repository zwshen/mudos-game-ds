// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�e�s�����D"NOR);
	set("long", @LONG
�A���b�@�ƱƩ��_�ӤW���۶����W�A�۶��W�^�ۦU�ج��R���[���A�ұƥX������
�˦����H��i�ҫ�C�q�o���F�������h�i�H��F���Z�}���ۦW���Ӫ���A���誽����
�O���F�[�ǰ|�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room047",
	    "west" : __DIR__"room051",
	    "south": __DIR__"room044",
	    "north": __DIR__"room046",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
