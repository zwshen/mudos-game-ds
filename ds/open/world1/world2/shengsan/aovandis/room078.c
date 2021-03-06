// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"珠寶店"NOR);
	set("long", @LONG
你在一間珠寶店裡，櫃子裡有好多的貴重寶石及名貴裝飾品，城裡的
居民都會在這買到他們所喜愛的耳環、項鍊、戒指等等漂亮的飾品，種類
繁多，目不暇給。牆上有個佈告牌(note)。
LONG
	);
	set("item_desc", ([
	"note":@NOTE
[1;32m
佈告牌上寫著:

		buy       向老闆買東西
		list      老闆會告訴你這裡賣些什麼
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room012",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss1.c" : 1,
	]));

	set("no_clean_up", 0);
	set("valid_startroom",1);
	set("light", 1);
	set("room_type","sell");	

	setup();
	replace_program(ROOM);
}