#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"Naboo 城市中心"NOR);
	set("long", @LONG
這是Naboo城的市中心，你可以在這裡看見北邊有一座宏偉的
皇宮。由於這裡被森林包圍著，所以給你一種清新自然的感覺。往
東面可以通往Naboo城最大的森林。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road7",
  "west" : __DIR__"road10",
  "north" : __DIR__"road4",
  "south" : __DIR__"road3",
]));
		 set("objects",([
 	 __DIR__"npc/police":2,
	__DIR__"npc/obj/pot":1,
 ]));

	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);

}
