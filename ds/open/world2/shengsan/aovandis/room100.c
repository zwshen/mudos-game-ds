// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"盜賊工會"NOR);
	set("long", @LONG
這裡是高級盜賊練習技能的房間，有位盜賊導師在這教導學生盜賊技能。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room087",
            ]));
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/thief_master" : 1,
        ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}