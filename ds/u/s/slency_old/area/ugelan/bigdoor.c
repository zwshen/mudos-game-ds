// Room: /u/s/slency/area/ugelan/bigdoor.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"城門口"NOR);
	set("long", 
"這裡是方圓百里內最大的城堡【幽遮蘭城】的城門口，你看到\n""人車不停地來往，整座城充滿了熱鬧氣息，在這裡可以清楚看見到\n""城內的金碧輝煌，你不禁想即刻進去瞧瞧。\n\n"	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road1",
  "south" : __DIR__"farm5",
]));
	set("light",1);
	set("objects", ([ /* sizeof() == 2 */
 __DIR__"npc/bigguard" : 1,
 __DIR__"npc/guard1" : 4,
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
setup();
	replace_program(ROOM);
}
