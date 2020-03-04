#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "»öªù");
    set("long",@LONG

            [31m¢©[0m                  [31m¢¨[0m
          [31m¢¨[41m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[40m¢©[0m
        [31m¢¨[41m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[40m¢©[0m
      [31m¢¨[41m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[40m¢©[0m
    [31m¢¨[41m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[40m¢©[0m
       [30m  [47m     ¢[0m                [47m ¢i¢i¢[0m 
     [37m¡´[0m  [47m¢i¢i¢i[0m                [47m¢i¢i¢i[0m  [37m¡´[0m
     [36m¢i[0m  ¢ª[47m¢i[0m¢«                ¢ª[47m¢i[0m¢«  [36m¢i[0m
[30m [0m¢©¢¨[36m¢i[0m¢©¢¨[47m¢i[0m¢©                ¢¨[47m¢i[0m¢©¢¨[36m¢i[0m¢©¢¨
[30m [37;47m¢i¢i[36;40m¢i[0;1;30;47m¢[1mi[1m¢[1mi[1m¢[1mi[0m¢i                ¢i[47m¢i¢i¢i[36;40m¢i[37;47m¢i¢i[0m
[30m [37;47m¢i¢i[36;40m¢i[0;1;30;47m¢[1mi[1m¢[1mi[1m¢[1mi[0m¢«                ¢ª[47m¢i¢i¢i[36;40m¢i[37;47m¢i¢i[0m

LONG
    );
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"path1",
  "south" : __DIR__"way3",
]));

	set("objects",([
  __DIR__"npc/guard" : 2,
]));
	set("no_clean_up", 0);
        set("light",1);

	setup();
	replace_program(ROOM);
}
