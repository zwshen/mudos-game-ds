// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�����줽��"NOR);
	set("long", @LONG
��W������J�����A�~�F�@���A�@�ݴN���D�o�̤��O�@��H���줽��
�C��ӳo�O���Z�}���������줽�a�I�C�b�L���줽��W�i�H�ݨ�ܦh����
�b�W���A�i���L���ɬO�h�򪺱M�󥫬F�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	  //  "west" : __DIR__"room061",
	    "north": __DIR__"room017",
            ]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/mayor" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
