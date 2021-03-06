// Room: /u/a/acme/area/ndoor.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "北武門");
     set("light",1);
	set("long", @LONG
這裡是天山天城的北城門，城門上有三個黑色大字，上面寫著【北武
門】，往北走可離開天城而通往天池，南邊可至天城的市集。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"pathway2.c",
  "north" : __DIR__"pass",
]));
	set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/garrison" : 3,
]));
	set("no_clean_up", 0);

	setup();
        create_door("north","北城門","south",DOOR_OPENED,"nokey");
}
int valid_leave(object me, string dir)
{
       if( dir=="north" && me->query("sky_city_war") )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}
