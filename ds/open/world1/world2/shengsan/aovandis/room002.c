// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�e�s�����D"NOR);
	set("long", @LONG
�A�b�@�ӫn�_���V���e�s���D�W�A���D��Ǫ��Ƥ����]�O�Ѭ��R���[
���Ҭ䦨�A�Ƥ����\�W���Ϯ׬O�@�������|��ൣ�mø�[�����ʪ��ѥ[�@
�~�A�o�w�g�O���Z�}�����@�j�S��F�A���_�i��F���������ߦa�a�C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "south": __DIR__"room023",
	    "north": __DIR__"room001",
            ]));
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/bird2" : 3,
        ]));
	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}