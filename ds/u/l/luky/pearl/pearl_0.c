// Room: /u/l/luky/room/pearl_0.c
#include <ansi.h>  //­Y­n¥Î¦³ÃC¦âªº¶·¥[¦¹¦æ
#include <room.h>
inherit ROOM;
void create()
{
set("short","[1;32m¤pÂí¤J¤f[m");
set("long", @LONG

[1;34;44m                  ¢d¢d¢d¢d¢d¢d¢d¢d¢d¢d¢d¢d¢d¢d¢d                   [m
[1;34;44m                ¢¨ùþùþùþùþùþùþùþùþùþùþùþùþùþùþùþ¢©                 [m
[1;34;44m             ¢ªùþùþùþùþùþùþùþ[1;37mºÑ¹pº¸Âí[1;34mùþùþùþùþùþùþùþ¢«              [m
[1;34;44m¢u¢q¢q¢q¢q¢q¢q¢q¢q¢m¢n¢z¢w¢w¢w¢{¢x¢z¢w¢w¢w¢{ ¢m¢n¢q¢q¢q¢q¢q¢q¢q¢q¢t[m
[1;34;44m¢u¢r¢r¢r¢r¢r¢r¢r¢r¢m¢n¢x      ¢x¢x¢x      ¢x ¢m¢n¢r¢r¢r¢r¢r¢r¢r¢r¢t[m
[1;34;44m¢¥  ..  '. "      ¢m¢n¢x      ¡³¢x¡³      ¢x ¢m¢n"      .'   "   ¢§[m
[1;34;44m¢¥   "      .  .  ¢m¢n¢x      ¢x¢x¢x      ¢x ¢m¢n    .     "     ¢§[m
[1;34;44m¢¥ '  " .'   "    ¢m¢n¢|¢w¢w¢w¢}¢x¢|¢w¢w¢w¢} ¢m¢n:     '    ."   ¢§[m
[1;34;44m¢r¢w¢w¢w¢w¢w¢w¢w¢yùþ¢o¢w¢w¢w¢w¢w¢r¢w¢w¢w¢w¢w|ùþ¢o¢w¢w¢w¢w¢w¢w¢w¢w¢r[m

LONG
);
set("exits", ([ /* sizeof() == 2 */
"east" : __DIR__"sea1",
"enter" : __DIR__"pearl_1",
]));
set("no_clean_up", 0);
set("light",1);
set("outdoors",1);
setup();
}
