// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�ĤG�ӵ�"NOR);
	set("long", @LONG
�o�O�@���������s�����x��D�A���ǰ����F�U�a�t�P�Φ����@���T��
���A�H�Ω��a�\��b�M�Ӹ̪��ӫ~�C���\�h�}�󪺦~���H�b�J�Ӫ��D��L
�̷Q�n���ӫ~�C
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
	    "west" : __DIR__"room060",
	    "south": __DIR__"room068",
	    "north": __DIR__"room011",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}