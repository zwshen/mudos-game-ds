// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�W�h���D"NOR);
	set("long", @LONG
�A���b�@�ƱƩ��_�ӤW���۶����W�A�۶��W�^�ۦU�ج��R���[���A��
�ƥX�����˼˦����H��i�ҫ�C�M�ӳo�̽T���\�h���}��H��b�o�̻E��
�A�q�o���F���O�A����~���A���訫�h�h�O���p�ĳ̳��w�h���}�G�ΡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room095",
	    "west" : __DIR__"room096",
	    "south": __DIR__"room091",
	    "north": __DIR__"room084",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}