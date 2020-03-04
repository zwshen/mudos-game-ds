// Room: /u/l/luky/room/pearl_8.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"¬Ã¯]«nµó"NOR);
set("long", @LONG

¡Ä¡Ä¡Ä¡Ä¡Ä   §A¥¿¨«¦b¼ö¾xªº¤jµó¤W¡C«n¤è¬O¥»Âí  ¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä
"  .   -   °ß¤@ªº¤@¶¡[1;33m®ÈÀ][m¡A¤£¤Ö¤H¶i¶i¥X¥Xªº¡A     -  '    "
:      -   ¥Í·N¦ü¥G«Ü¦n¡C©Î³\§A¥i¥H¦b³o¸Ì¹J¨£     -    "  :
= ."   -   §A¦h¤é¤£¨£ªº¾Ô¤Í¤]»¡¤£©w¡C             -       =
==-  " -       -                          -       - .   -==
¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã ¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã

LONG
);
set("exits", ([ /* sizeof() == 3 */
"west" : __DIR__"pearl_9",
"south" : __DIR__"pearl_35",
"east" : __DIR__"pearl_7",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
