// Room: /u/a/acme/area/pass7.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "山路");
	set("long", @LONG
此處便是通往天城的山路，往西瞧去可看見天城的城門，遠遠向東望
去有一條小溪，還有座大木橋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"edoor",
  "east" : __DIR__"wewd",
]));
	set("no_clean_up", 0);
       set("outdoors","land");

	setup();
        create_door("west","東城門","east",DOOR_OPENED,"nokey");
}
