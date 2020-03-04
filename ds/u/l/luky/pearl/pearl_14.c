// Room: /u/l/luky/room/pearl_14.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"¬Ã¯]µóÂà¨¤"NOR);
set("long", @LONG

[1;33m                           ¢y[31m¢©[m
  §A¬Ý¨£¥_¤è¦³®y»È¦æ[1;33m ¢¨[43mùùùùùùùùùùùù[40;37m¢©[m  ¦Ó§Aªº¦è¤è«h¬O¤@¶ô¤j
ªÅ¦a¡C¦A¦VªF¦æ«h[1;33m     [43m¢m¥Ð¥Ð¥Ð¥Ð¥Ð¥Ð [40;37m¢m[m ¬O¥»Âíªº°Ó«~ªº¶°´²¤¤
¤ß¡C            [1;33m¢¨¢e¢i[43m¢e¢i¢e¢i¢e¢i¢e[40m¢i¢e[37m¢©[m
¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä[1;33;43m¢i     ¡ò   ¡ò   ¡ò     [37m¢i[m¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä
"  .   -         :[43;30m¢©  ¡½[1;37m ¶®¥§»È¦æ[0;30;43m ¡½  ¢¨[m:  -       -  '    "
:      -         :¢y[43;30m       ¢¨¢©       [m¢j:  -       -    "  :
= ."   -       - :¢y[1;43;33m  ¥Ð ¡±[0;30m¢p¢i[1;33;43m¡± ¥Ð  [m¢j:  -       -       =
==-  " -       - :¢y[1;43;32m ¡Ý¡Ý  [0;30m¢p¢i[1;43;32m  ¡Ý¡Ý [m¢j:  -       - .   -==
¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã  ¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã
LONG
);
set("objects",([
__DIR__"npc/sightseer":1,
]));
set("exits", ([ /* sizeof() == 4 */
//"north" : __DIR__"pearl_30",      
"west" : __DIR__"pearl_31",
"south" : __DIR__"pearl_13",
"east" : __DIR__"pearl_15",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
