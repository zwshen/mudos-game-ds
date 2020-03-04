// This is a room made by roommaker.
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "小茅屋");
	set("long", @LONG
一間頗為寒酸簡陋的小茅屋，在這萬象帝都裡居然會出現如此的房
舍倒是令人有些驚訝，不過看著灶旁的老婦人正辛苦地照顧家務，不免
感到皇廷貴族與貧苦居民的強烈差異。
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road11",
]));
	create_door("west", "木門", "east", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
