#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST.FIRE＠DPY地下三樓"NOR);
	set("long", "再下一層，你聽到有一大班人在喧嘩，原來是一個喝醉了的人在醉酒
鬧事，看起來那人很兇猛，你還是小心為妙‥‥‥向上走便是你剛來的二
樓。\n");
 set("exits",([ 
"up":__DIR__"dpy2.c",
]));
        set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/q1" : 1,
]));
set("light", 1);
	setup();
	replace_program(ROOM);
}
