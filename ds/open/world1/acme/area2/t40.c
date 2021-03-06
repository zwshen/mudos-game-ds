// Room: /u/a/acme/area2/t40.c

#include <room.h>

inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "幽冥地窖[地下四層]");
	set("long", @LONG
你正走在黑暗無比的地道中，地道窄又長，好像走不完似的，越
往裡頭心裡越害怕，這股黑暗的氣流令你窒息。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"t41",
  "southwest" : __DIR__"t39",
]));
      set("objects",([
         __DIR__"npc/sun" : 1,
      ]));
  set("item_desc", ([ /* sizeof() == 1 */
      "大門" : "這是一扇紅色的大門，門似乎上了鎖。\n",
      "紅色大門" : "這是一扇紅色的大門，門似乎上了鎖。\n",
  ]) );
 
  set("hide_exits", ([
  ]));
	set("no_clean_up", 0);


	setup();
	create_door("south","紅色大門","north",DOOR_LOCKED,"redkey");
}
