// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ĵ�ƶ��줽��"NOR);
	set("long", @LONG
�A�ݨ�����W���ۦn�h��ĵ���A�۷��ޤH�`�ءA�i�H�ݥX�o��ĵ��
�����������O�R���a�A�P���nĵ�áC�L�̪��u�@�N�O���ޫ��̡A��������
���w��ί��ǡC�L�̥��b�줽��W�줽�ۡC
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room037",
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