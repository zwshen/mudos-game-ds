// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�������s��"NOR);
	set("long", @LONG
�����̦��W���s���O�b�o�C�y���A���\�h�ȤH���O���q���~�}�W�Ө�
���C�a�x�W����հs�v���b�ջs���J�����s�A��W���ӧi�ܵP(sign)�C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room068",
	    "down" : __DIR__"room106",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss3" : 1,
	]));
        set("item_desc", (["sign":@NOTE

�G�i�P�W�g��:  �s�K���}���A�}�����ܰs�C

	==========================
	���~�M��	list
	�ʶR���~	buy <���~>
	==========================

NOTE
        ]) );

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

