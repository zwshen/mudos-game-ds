// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"百貨公司"NOR);
	set("long", @LONG
所有時髦的高級貨在這邊都找得到，這裡是市民逛街購物必經的地點
，尤其是到了假日，人潮之洶湧可喻為奇景。南邊的廣場還有一座小型的
水池，水池上有個水車不停的受到由上而下的細細水流牽引而轉動。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room088",
	    "west" : __DIR__"room099",
            ]));

	set("objects", ([ /* sizeof() == 1 */
//		__DIR__"npc/boss.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}