// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�W�h���D"NOR);
	set("long", @LONG
�A���b�@�ƱƩ��_�ӤW���۶����W�A�۶��W�^�ۦU�ج��R���[���A��
�ƥX�����˼˦����H��i�ҫ�C�A�i�H�M�����ݨ즳�۷��H��b�o�̳q
�L�A�o�̬O�@�ӥ������ӷ~�ϡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"room024",
	    "north": __DIR__"room088",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}