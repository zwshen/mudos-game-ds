// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"����U�ݤ��q"NOR);
	set("long", @LONG
�o�����q�O���ӷ~���q�A�M�������Ʒ~�C��Ǫ�����Ǧ��X�Ӭ֮�
�A���C���G�զ⪺��t�C���q���C�ӤH�����ۤu�@�A�̭��٦����|ĳ�ǡA
���G���H�b�̭��}�|�C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room098",
	    "south": __DIR__"room019",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss0.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}