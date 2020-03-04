// Room: /u/a/acme/area/hunter.c
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "木屋");
     set("light",1);
	set("long", @LONG
這裡是一間頗為簡陋的小屋，屋內各只有一張桌椅，牆上掛了支長弓
，還有一俱大象的頭骨，往西有個出口，是通往小屋的後院。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"backyard",
  "south" : __DIR__"pass8",
]));
    set("objects",([
       __DIR__"npc/hunter" : 2,
    ]) );
	set("no_clean_up", 0);
	setup();
       create_door("west", "木門", "east", DOOR_CLOSED);
}
