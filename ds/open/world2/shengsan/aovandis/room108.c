// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�\\�U��"NOR);
	set("long", @LONG
�Ǥ������C�O�ݩ�ŷx��աA���A���ئ^�a���Pı�A�@�Ǫ����^�n�u
���ۨ嶮�Χ籡���ֳ��A�ϧA�������������ܬ����M�C��W�{�{���w����
��U�N�ۡA��~�����ᦷ�O�M��~�Ħ����s�A�ᦷ�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room107",
            ]));
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/thief0.c" : 1,
        ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

