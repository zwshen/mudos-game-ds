// Room: /u/s/slency/area/ugelan/royalty.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"『 皇宮大門 』"NOR);
	set("long", @LONG
你來到了大門前，不過大門卻是深鎖著的，門上鎖著特製的鋼鎖, 
看來尋常兵器是無法將其破壞的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"royalty2",
  "south" : __DIR__"royalty",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
