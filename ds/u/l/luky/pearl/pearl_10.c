// Room: /u/l/luky/room/pearl_10.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short", HIG"¬Ã¯]µóÂà¨¤"NOR);
set("long", @LONG

[31m¢©[m
[41;31m¢i[m¢­         ³o¸Ì¬O¬Ã¯]µóªºÂà¨¤¡C©¹ªF¬O¬Ã¯]«nµó¡A      ¡Ä¡Ä
[41;31m¢i[m :¢­     ©¹¥_¬O¬Ã¯]¦èµó¡C¦è¤è¦³¤@´É¤é¦¡ªº«Ø¿vª«    ¢¬:   
[41;31m¢i[m : :¢j   ¡A¬õ¦âªº¤jªù®ÇÁÙ±¾¤F¤@­Ó©ÛµP(Sign)¡C§A  ¢y: :   
[41;31m¢i[m : :¢j   ªº«n¤è¬O¤@¶¡ÃÄ©±¡A§A¥i¥H¦b¨º¸Ì¶R¨ÇÃÄ¥H  ¢y: :  =
[41;31m¢i[m :¢¬     ³Æ¤£®É¤§»Ý¡C                              ¢­:  =
[41;31m¢i[m¢¬                                                   ¡Ã¡Ã
[31m¢«[m
LONG
);
set("exits", ([ /* sizeof() == 4 */
 "north" : __DIR__"pearl_11",
 "west" : __DIR__"pearl_33",
 "south" : __DIR__"pearl_34",
 "east" : __DIR__"pearl_9",
]));
set("item_desc",([
  "sign":"©ÛµP¤W¼gµÛ¬n¤C§á¤Kªº¥|­Ó¤j¦r"HIY"¡i¤Ñ¹D¹D³õ¡j¡C\n"NOR,
  "©ÛµP":"©ÛµP¤W¼gµÛ¬n¤C§á¤Kªº¥|­Ó¤j¦r"HIY"¡i¤Ñ¹D¹D³õ¡j¡C\n"NOR,
]));
set("no_clean_up", 0);
set("light",1);
create_door("west","¬õ¦â¤jªù","east",DOOR_LOCKED,"red_key");
setup();

}
