// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���߹Ϯ��]"NOR);
	set("long", @LONG
�o���æ��״I���ϮѡA�A�ݨ�k�����䦳�@�ƹq��(computer)�A���G
�i�H�z�L�q���d�ߧA�n���ϮѡC�{�N�ƪ��ϮѬd�ߪ��T���A�٤U���֪���
���C��W���ӧi�ܵP(note)�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north": __DIR__"room121",
	]));

	set("objects", ([
		__DIR__"npc/obj/pc_lib":1,
	]));

	set("item_desc", (["note":@NOTE
�G�i�P�W�g��:

	�A�i�H�Q�ιq��(computer)�d�߹ϮѡA�p�G�T�w�n�Y���Ϯ�
	�q���]�|�H�̧֪��t�׬��z���X�A�n�����y�C

NOTE
        ]) );

	set("no_clean_up", 0);
	set("no_recall",1);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}