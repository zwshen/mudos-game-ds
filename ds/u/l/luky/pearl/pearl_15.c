// Room: /u/l/luky/room/pearl_15.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"¬Ã¯]¥_µó"NOR);
set("long", @LONG

¡Ä¡Ä¡Ä¡Ä¡Ä   ³o¸Ì¬O¬Ã¯]¥_µó¡A¤]¬O¥»Âíªº¥æ©ö­«¦a  ¡Ä¡Ä¡Ä¡Ä¡Ä
"  .   -   ¡C¸ô®Ç©ñ¤F´X­Ó¤j½c¤l¡A©Î³\¬O©±®a¤£­n   -  '    "
:      -   ¦Ó°ï©ñ¦b¸ô®Çªº§a¡C§A¦ü¥GÅ¥¨ì¦³¤H¦b  ¡Ä¡Ä¡Ä  "  :
= ."   -   »¡¸ÜªºÁn­µ¡A¥i¬O¨Ã¨S¦³¤H°Ú¡H©Î³\¬O¢y[33m¢ª¢i¢i¢©[m   =
==-  " -   §Aªº¿ùÄ±§a¡C                      ¢y  ¢j  ¢y  ==
¡Ã¡Ã¡Ã¡Ã¡Ã             ¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¢­¢j  ¢y¡Ã¡Ã
                                                 ¡Ã¡Ã¡Ã
LONG
);
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_14",
"east" : __DIR__"pearl_16",
]));
set("item_desc",([
//  "box":"¤@­Ó¸ËªF¦è¥ÎªºªÅ½c¤l¡C\n",
//  "½c¤l":"¤@­Ó¸ËªF¦è¥ÎªºªÅ½c¤l¡C\n",
]));
set("no_clean_up", 0);
set("light",1);
set("objects",([
__DIR__"obj/box1":1,
]));
setup();
}
