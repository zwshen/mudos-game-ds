// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�W�h���D"NOR);
	set("long", @LONG
�A���b�@�ƱƩ��_�ӤW���۶����W�A�۶��W�^�ۦU�ج��R���[���A��
�ƥX�����˼˦����H��i�ҫ�C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "south": __DIR__"room052",
        "enter": __DIR__"room103",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
}

void init()
{
  this_player()->set_temp("now_old_city",1);
  this_player()->set_temp("now_new_city",0);
}
