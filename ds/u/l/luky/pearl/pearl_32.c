// Room: /u/l/luky/room/pearl_32.c
#include <path.h>
#include <room.h>
inherit ROOM;
void create()
{
//seteuid(getuid()) ;
set("short", "[1;33m®ü©³¤ë¥x[m");
set("long", @LONG

[44m                                                        [m
[30;44m       ¡Ë                           ¢l¢©        ¡Ë      [m
[30;44m                    ¡Ë           ¢¨ ¢l¢i¢©              [m
[1;33;44m      ¡´[0;30;44m                       ¢¨¢i ¢l¢i¢i              [m
[30;44m                             ¢¨¢i¢i ¢l¢i¢i              [m
[30;44m                           ¢ª¢f¢f¢i¢i¢i¢f¢f¢h¢«         [m
[1;34;44m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[m

LONG
);
set("exits", ([ /* sizeof() == 2 */
 "east" : __DIR__"pearl_27",
 "climb" : __DIR__"ship",
]));
set("objects",([
//"/u/l/luky/room/tempship":1,
]));
 set("outdoors",1);
 set("light",1);
 set("no_clean_up", 0);
 setup();
 load_object(__DIR__"ship");
}
