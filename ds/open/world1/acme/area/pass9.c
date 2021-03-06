// Room: /u/a/acme/area/pass9.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "山路");
	set("long", @LONG
你正走在一條筆直的山路上，路上舖了石板階梯，讓人覺得如履平地
，絲毫不覺得是在爬山，拾級而上，可望見天城的城門，向南望去有個小
小的黃沙山丘。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"pass10",
  "northup" : __DIR__"sdoor",
]));
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
        create_door("northup","南城門","southdown",DOOR_OPENED,"nokey");
}
