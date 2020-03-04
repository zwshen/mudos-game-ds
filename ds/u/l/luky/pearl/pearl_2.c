// Room: /u/l/luky/room/pearl_2.c
#include <path.h>
inherit ROOM;
void create()
{
set("short","[1;32m¬Ã¯]µó[m");
set("long", @LONG

ùþ¢­                                                   ¢¬ùþ
ùþ :¢­    ±æ¶i²´Ã®ªº¬O¤@¤ùÁcµØ¼ö¾xªº´º¶H¡A¯uÅý¤HÃø   ¡Ä¢jùþ
ùþ : :¢j¥H¬Û«H³o¬O¦b®ü­±¤U¤T¸U¦h¤½¤Øªº¦a¤è¡C®ÇÃäªº ¢y: ¢jùþ
ùþ : :¢j³òÀð°{Ä£µÛ¤C±mªº¥ú¨~¡A§Aµo²{³o¨Ç³òÀð©~µM³£ ¢y: ¢jùþ
ùþ :¢¬  ¥Î¬Ã¯]°ï¬ä¦Ó¦¨ªº¡IªFÃä¬O¥»Âíªº¤jªù¡C         ¡Ã¢jùþ
ùþ¢¬                                                   ¢­ùþ

LONG
);
set("exits", ([ /* sizeof() == 3 */
"north" : __DIR__"pearl_21",
"south" : __DIR__"pearl_3",
"east" : __DIR__"pearl_1",
]));
set("objects",([
__DIR__"npc/swimmaster": 1,
]));

set("no_clean_up", 0);
set("light",1);
setup();
}
