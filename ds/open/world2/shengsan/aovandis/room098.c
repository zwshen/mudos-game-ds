// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"投資顧問公司會議室"NOR);
	set("long", @LONG
會議室內有個長型的會議桌，桌上有麥克風，在中間還有個液晶投影
機。地板是大理石和琉璃混和而成的特殊石材所造的，從窗外射進的陽光
照在地上格外的耀眼。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room086",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}