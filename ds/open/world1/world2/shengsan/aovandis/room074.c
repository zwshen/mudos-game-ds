// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�x�~��"NOR);
	set("long", @LONG
�A�ݨ���W�αM�d���\�ۦn�h�U���U�˪��������Z���A�ݨ�o�Ǥ��g
���A���m�ʪ��İʡA�p�G�ݭn�i�H�����R�A�Q�n���Z���C�A�`�N����W
���ӥΤ�O�v�����i�ܵP(note)�C
LONG
	);
	set("item_desc", (["note":@NOTE

�G�i�P�W�g��:

	�ݦs�f�Х� <list>      <list wp>       <list eq>
	�n�R�F��� <buy ���~>  <buy �ƶq ���~>
	�n��F��� <sell ���~> <sell all>      <sell �ƶq ���~>

NOTE
        ]) );
	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room062",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss.c" : 1,
	]));


	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","shop");
	setup();
	replace_program(ROOM);
}