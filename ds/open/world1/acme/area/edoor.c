// Room: /u/a/acme/area/edoor.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
set("short","東華門");
     set("light",1);
	set("long", @LONG
這裡就是位於天山的天城了，這是天城的東邊城門，只見城門上寫
了三個黑色大字【東華門】，石門看起來相當的老舊，因年久失修，不
時的掉落一塊塊的小石子，似乎不多久便會傾倒。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"street5",
  "east" : __DIR__"pass7",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/garrison" : 3,
]));
	set("no_clean_up", 0);

	setup();
        create_door("east","東城門","west",DOOR_OPENED,"nokey");
}
int valid_leave(object me, string dir)
{
       if( dir=="east" && me->query("sky_city_war") )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}
