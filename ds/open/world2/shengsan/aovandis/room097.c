// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�u�Ԫ��a"NOR);
	set("long", @LONG
�o���a���\������o���M���Ǫ����ЬO�u�Ԫ���ҡA���M�o�O�o���a
�A���O�o���`�ݨ�u�ԥ��H�F�ۤϪ��o�`�`�ݨ줣���H�h�b�o�̬y�s�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room084",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}