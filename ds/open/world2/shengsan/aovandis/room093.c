// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���ŻȦ�"NOR);
	set("long", @LONG
�o���Ȧ�۷����W�ҡA��b�����ҫ����H���M��n�C�Ȧ���{�u��
�b���Ȥ�A�ȡA�����O���Ȧ��V���V�j�A�Ȥ�V�ӶV�h�C���@���O�l(board)
�W�������i���F��A�]�\�A�Ӭݤ@�ݡC
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room088",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss3.c" : 1,
	]));

	set("item_desc", (["board":@NOTE
[1;32m
�G�i�P�W�g��:

	deposit		�}��G�s��
	withdraw	���

[m
NOTE
        ]) );

	set("no_clean_up", 0);
	set("valid_startroom",1);
	set("light", 1);
	set("room_type","bank");	// �Ȧ����

	setup();
	replace_program(ROOM);
}