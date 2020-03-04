// Room: /u/l/luky/room/pearl_17.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"¬Ã¯]¥_µó"NOR);
set("long", @LONG

[1;31m                                     ¢d¢d¢d¢d¢d¢d¢d¢d
                                   ¢y[41m¢i¢i¢i¢i¢i¢i¢i¢i[40m¢j[m
¡Ä¡Ä¡Ä¡Ä¡Ä   §A¥¿¨«¦b¼ö¾xªº¤jµó¤W¡C¡Ä[30;47mùø¡İ¡İ¡İ¡İ¡İ¡İùø[m¡Ä¡Ä¡Ä
"  .   -   ³\¦h·í¦aªº¦~»´¤H¦b³o¸Ì»E  [30;47mùø[35m ¦Û°Ê³c½æ¾÷[30m ùø[m     "
:      -   ·|²á¤Ñ¡C§A¬İ¨ì¦èÃä¦³¤@´É  [30;47mùø¡İ¡İ¡İ¡İ¡İ¡İùø[m  "  :
= ."   -   ¤j©Ğ¤l¡A¤H¨Ó¤H©¹ªº¦n¤£¼ö  [30;47mùø¡°¡°ùúùû¡°¡³ùø[m     =
==-  " -   ¾x¡C®ÇÃä¦³¤@¥x¦Û°Ê³c½æ¾÷  [30;47mùàùùùùùäùäùùùùùâ[m   -==
¡Ã¡Ã¡Ã¡Ã¡Ã ¡C                      ¡Ã[30;47mùø[32mInsert coins[30mùø[m¡Ã¡Ã¡Ã
                                     [30;47mùà¢¤¢¤¢¤¢¤¢¤¢¤ùâ[m


LONG
);
set("objects",([
__DIR__"npc/playboy":1,
__DIR__"obj/automat":1,
]));
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_16",
"east" : __DIR__"pearl_18",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}
