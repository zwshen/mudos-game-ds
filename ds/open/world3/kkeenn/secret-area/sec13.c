#include <room.h>
inherit ROOM;
void create()
{
        set("short", "MUSIC ROOM");
        set("long", @LONG
³o¸Ì´N¬O¤j®a¥­®É°²¤é¨S¤u§@®É³Ì±`¨ìªº¥ð®§¤§³B¡A¨Ó³o¸Ì»P¿ËªB¦n
¤Í¡B¼Ó¤W¼Ó¤Uªº¦n¾F©~¡A¤j®a§Ö§Ö¼Ö¼Öªº°ªºq¤@¦±¡A·Ç³Æªï±µ©ú¤Ñªº¤u§@
¡C®ÇÃä­¼²Dªº¤j¾÷±ñ³Ê¤W±¾µÛ¤@¥»¤p¥U¤l( List )¦n¹³¬Oµn°Oºq¦±½s¸¹¥Î
ªº¡AÂI°Û¾÷´N¦b®ÇÃä( «ü¥O: singing ½s¸¹ )¡C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "up":__DIR__"sec5.c",
     
]));
        set("item_desc", ([
        "list" :"
====================[33m¦±[0m                    [33m¥Ø[0m======================== 
¤@¡B ·Å¬X
¤G¡B ¶W§Ö·P
¤T¡B Don't say you love me §O»¡©p·R§Ú
¥|¡B §A·R§Ú¶Ü(·R¦b¤ß¸Ì½¯©µª©)
¤­¡B ±w±o±w¥¢
¤»¡B §Ú·|·Q©p
¤C¡B ¬O§AÅÜ¤F¶Ü¡H
¤K¡B ªB¤Í
¤E¡B ¤@À»§Y¤¤
¤Q¡B ¤@¤F¦Ê¤F
¤Q¤@¡B §O¨ÓµL®~
¤Q¤G¡B I love you µL±æ
¤Q¤T¡B «Î³»
¤Q¥|¡B ¤p©j ³o¬O§Úªº¦W¤ù
¤Q¤­¡B ¤T½P¤T¤é
¤Q¤»¡B ¯d¤ß
¤Q¤C¡B «Ü·R«Ü·R§A
¤Q¤K¡B FIRST Love
¤Q¤E¡B LIGHT THE LIGHT (American Edition)
¤G¤Q¡B ¬ù©w
¤G¤Q¤@¡B ³æ²´¥Ö¤k¥Í
¤G¤Q¤G¡B ¤À¨É
¤G¤Q¤T¡B ¤f­»¿}
¤G¤Q¥|¡B ·Rªº¥N»ù
¤G¤Q¤­¡B ·Q·R
¤G¤Q¤»¡B ¤Ö£{§A§Ú¸Ó«ç»ò¿ì
¤G¤Q¤C¡B ­·ºå 
¤G¤Q¤K¡B ºñ¥ú
¤G¤Q¤E¡B ¬O¶Ü
¤T¤Q¡B ¤@­Ó¤Hªººë±m
¤T¤Q¤@¡B ¤Ñ¤Ñ¶}¤ß

[36m(ÂIºq¥Îsinging ½s¸¹ [for ¤H])[0m
============================Update By Kkeenn@DS 2001/12/30==================
/n",
        ]));

        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/singer.c"   :1,
]));

        setup();
        replace_program(ROOM);

}
