// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ӫ���"NOR);
	set("long", @LONG
�M�s���Ů�����O�o�̪��Ӫ��һs�y�X�Ӫ��A�o�ǪŮ����Aı�o�Y��
�ܱo�M�s�N�R�C�U���U�˪��Ӫ����b�A�������U�F�A�A�ݨ즳�\�h�i�R��
�p�ͪ��b�䤤���A���֡C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "north": __DIR__"room110",
            "east" : __DIR__"room113",
	    "south": __DIR__"room114",
	    "west" : __DIR__"room111",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

