// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ӫ���"NOR);
	set("long", @LONG
��ö�������C�Ȧb�o�[��o�̪��@��@��A���ɧA�|�ݨ�ĵ����^�x
�n��������A���زM�n���������A���W���F�L�ӡA�P�򦳦n�h�_�Ყ���
�U�ت��i�R�p���ΡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "north": __DIR__"room116",
            "east" : __DIR__"room119",
	    "west" : __DIR__"room113",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boy0" : 1,
		__DIR__"npc/girl0" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

