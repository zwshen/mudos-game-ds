#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST。Gate＠South"NOR);
	set("long", @LONG
這裡就是大城市Saint的南城門，都是人流密集的其中一個地方，因為
這個南城門是交通的樞紐，終日人來人往，所以人們都給這道城門一個特
別的稱呼－－【聖門】。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dst4.c",
"out":__DIR__"dst17.c",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
