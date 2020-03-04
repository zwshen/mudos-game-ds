#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "走廊間");
	set("long", @LONG
這裡是東西南北四邊的走廊之間，也是莊內通往北南必經的路徑，
經常有些人從這來往，這兒的屋頂有些漏洞，若是下雨了必會漏水，看
來沒有人來修理的樣子。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"flurry32.c",
  "south" : __DIR__"flurry24.c",
  "west" : __DIR__"flurry27.c",
  "east" : __DIR__"flurry29.c",
]));
	create_door("south","木門","north",DOOR_CLOSED);
	set("no_clean_up", 0);
	set("light",1);
	setup();
}
