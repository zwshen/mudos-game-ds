// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���߼s���F��"NOR);
	set("long", @LONG
�e��s���̪��a�W�O�ѦU���C�⪺�[���Ҭ䦨���A�C�Ѧ��᭺���ﱵ
�������N�O�o�Ǭ��R���[���j�F�C�A���b���Z�}�����߼s�����F���A���F
�����N�O�F�����F�A���n�N�O�u�ö��`�q�O�줽�ǡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room011",
	    "west" : __DIR__"room001",
	    "south": __DIR__"room060",
	    "north": __DIR__"room058",
            ]));
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/bird2" : 4,
        ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}