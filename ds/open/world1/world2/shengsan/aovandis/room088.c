// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�W�h���D"NOR);
	set("long", @LONG
�@�a�@�a�������A���C�b�o���^�ۦU�ج��R�[�����۶����ⰼ�A�y��
���@�������۵P�a���b�o���ӵ󪺨ⰼ�C�A�i�H�ݨ즳�n�h�n�h�������b
�o�̳}��C�q�o���訫�O���W�һ�j���ʳf���q�A���F�h�O���Ȧ�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room093",
	    "west" : __DIR__"room092",
	    "south": __DIR__"room089",
	    "north": __DIR__"room082",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}