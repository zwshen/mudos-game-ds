// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�W�Űө�"NOR);
	set("long", @LONG
�A���i�F�@���W�ūK�Q�ө��̭��A�A�o�{�o�̽檺�F������A��
�L�o���Q����ΡA�b�o�̧A�i�H�R��@�Ǥ�`�Ϋ~�M�@�Ǧ窫�C
��W�ٱ��ۤ@�ӧi�ܵP(sign)�C

LONG
	);
	set("item_desc", (["sign":@NOTE
[1;36m
�G�i�P�W�g��:
[1;32m
		buy       �V�����R�F��
		list      �ݬݳo�̦���Ǥ���
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room063",
	    "south": __DIR__"room066",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss6.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","sell");
	setup();
	replace_program(ROOM);
}