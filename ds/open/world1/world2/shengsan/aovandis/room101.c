// ���Z�}��
// LV 1~50
// �Ѱg�a�I
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�A����~���ܮw"NOR);
	set("long", @LONG
�n�h�n�h����A���~�\��b�o��A�@�쩱�����b�o�̻{�u�a�M�I�A��
�C�o�̪����u�ä����R���A���I�t�t���A�ӥB�A��b�a�O���Pı�n����
�U�O�ŪŪ��C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room095",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

