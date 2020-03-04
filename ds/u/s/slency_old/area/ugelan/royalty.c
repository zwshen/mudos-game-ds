// Room: /u/s/slency/area/ugelan/royalty.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"『宮廷廣場』"NOR);
	set("long", @LONG
這裡是皇宮大門前的廣場，門前站了許多侍衛，你約略可以從大門
鐵桿縫隙中望見皇宮內部的精緻建築，縱然大門深鎖，不過你仍然忍不
住想進宮一窺究竟。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"royalty3",
  "south" : __DIR__"pontlevis",
]));
	set("objects", ([ /* sizeof() == 1 */	
       __DIR__"npc/guard2" : 4,
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
