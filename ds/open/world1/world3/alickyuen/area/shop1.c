// updated 26/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;36mST．RecycleStation＠Robot[2;37;0m");
	set("long", @LONG
這裡是一間除了不值錢的東西之外，什麼都會回收的回收屋。而這裡
的回收價格和其他的都是一樣，所以都不會出現找續上的問題。而這裡的
回收工作是由機械人負責。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dst9",
]));
set("light",1);
	set("world", "future");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/seller.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
