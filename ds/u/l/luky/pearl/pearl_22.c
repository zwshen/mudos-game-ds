// Room: /u/l/luky/room/pearl_22.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIM"¬À·ä¤j¹D"NOR);
set("long", @LONG

[33m                          ¢c¢c¢c
[mùþ¢­[33m                  ¢c¢¨[31m¡Ý¡Ý¡Ý[33m¢c[m                     ¢¬ùþ
ùþ :¢j¡Ä¡Ä     ³o¸Ì¬O¬À·ä¤j¹D¡C¦è«n¤è¦³¤@®y  ¡Ä¡Ä¡Ä¡Ä¢y: ùþ
ùþ :¢j: :    ¼Ú¦¡ªº­×¹D°|¡A¦A©¹¥_¨«¬O¥»Âíªº   : : :  ¢y: ùþ
ùþ :¢j: :    °Ó©±µó¡C«n¤è¦³´X­Ó¥þ°ÆªZ¸Ëªº±Ð   : : :  ¢y: ùþ
ùþ :¢j¡Ã¡Ã   °ó¦u½Ã¨Ó¦^¨µÅÞµÛ¡C              ¡Ã¡Ã¡Ã¡Ã¢y: ùþ
ùþ¢¬                                                   ¢­ùþ

LONG
);
set("exits", ([ /* sizeof() == 2 */
"south" : __DIR__"pearl_23",
"north" : __DIR__"pearl_18",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
