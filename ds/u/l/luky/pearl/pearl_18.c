// Room: /u/l/luky/room/pearl_18.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"¬Ã¯]¥_µó"NOR);
set("long", @LONG

  ³o¸Ì¬O¬Ã¯]¥_µó»P[1;33m    ¢c¢c¢c¢c¢c¢c¢c[m  ¬À·ä¤j¹Dªº¥æ¤e¸ô¤f¡C©¹
«n«K¬O¬À·ä¤j¹D¡C[1;33m  ¢c[0;33m¢¨[31m  ¡Ý¡Ý¡Ý¡Ý¡Ý[1;33m¢y  ¢c[m  ¥_Ãä¦³­Óºë½oªº¹D¨ã
«Î¡C¾ã±øµó¥ÑªF[33m  ¢¨[1;33m  ¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¢y[m  ¦V¦è©µ¦ù¡C
¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä[33m¢i[m¡Ä[1;37m  ªüº¸¥[´µ¹D¨ã«Î[33m  ¢y[m¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä
"  .   -          ¢y[1;33m     ¡Ä¡Ä¡Ä¡Ä[m     ¢¬:          -  '    "
:      -          ¢y ¡ò[33m  ¢©[1;31m¢P¢P¢P[33m¢­[m¡ò ¢j:          -    "  :
= ."   -          ¢y[33m     ¢i[m ùæùçùè[1;33m ¢j[m ¢j:          -       =
==-  " -       -  ¢y[33m     ¢i[m ¢x¢x¢x[1;33m ¢j[m ¢j:  -       - .   -==
¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã

LONG
);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"pearl_22",
"north" : __DIR__"pearl_28",
"west" : __DIR__"pearl_17",
"east" : __DIR__"pearl_19",
]));
set("no_clean_up", 0);
set("light",1);
setup();
load_object(__DIR__"npc/item/greentea");
}
