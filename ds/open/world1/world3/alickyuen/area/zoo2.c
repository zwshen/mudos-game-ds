// Room: /u/a/alickyuen/area/zoo2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Road＠CyberZoo"NOR);
	set("long", @LONG
進了動物園，你首先看到的是一些比較可愛的小動物，有熊貓、長頸
鹿、烏龜等。令你目不暇給，一路走過去便可看到更多動物。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zoo4",
  "south" : __DIR__"zoo",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
