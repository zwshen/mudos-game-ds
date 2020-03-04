// Room: /u/a/acme/area/sdoor.c

#include <path.h>
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "«n¤Èªù");
     set("light",1);
	set("long", @LONG


[33m         ¢i¢i¢i    ¢i¢i¢i    ¢i¢i¢i    ¢i¢i¢i    ¢i¢i¢i    ¢i¢i¢i[0m
         [33m¢i¢i¢i    ¢i¢i¢i    ¢i¢i¢i    ¢i¢i¢i    ¢i¢i¢i    ¢i¢i¢i[0m
         [33m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[0m
         [33m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[0m  [36m¤Ñ    «°  [33m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[0m
[33m         ¢i[35m¤Ñ¤s¨q¥X«n¤æ³Ä¡A[33m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[35m¼v¸¨¤Ñ´ò«CÂL¥ú¡F[33m¢i[0m
         [33m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[33m¢~--------¢¡[33m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[0m
         [33m¢i[35m«Ì­·¤EÅ|¶³ÀA±i¡F[33m¢i¢i[33m¡ý   ¡ý   ¡ý[33m¢i¢i[35mª÷Âö«e¶}¤G®pªø¡C[33m¢i[0m
         [33m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[33m¡ý  .¡ý.  ¡ý[33m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[0m
         [33m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[33m¡ý   ¡ý   ¡ý[33m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[0m
         [33m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[33m¡ý   ¡ý   ¡ý[33m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[0m

         ³o´N¬O¤Ñ¤s¤Ñ«°ªº«n«°ªù¤F¡A³o¸Ì§A¥i¥H¬Ý¨ì¤H¨Ó¤H©¹¡A¦n
     ¤£¼ö¾x¡C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"street.c",
  "southdown" : __DIR__"pass9",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/garrison" : 3,
]));
	set("no_clean_up", 0);

	setup();
        create_door("southdown","«n«°ªù","northup",DOOR_OPENED);
}
int valid_leave(object me, string dir)
{
       if( dir=="southdown" && me->query("sky_city_war") )
                return notify_fail("¨º¸Ì¥u¦³ª±®a¤~¯à¶i¥h¡C\n");
        return ::valid_leave(me, dir);
}
