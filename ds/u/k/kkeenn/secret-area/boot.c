#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Train Station");
        set("long", @LONG
¥|©Pªº¤H¸s¤Q¤À¾ÖÀ½¡A¦b®ÇÃäªº°ª¬[¤W¦³¤@­Ó¨­¬ïÂÅ¦â¹q¨®¨îªAªº¤½
°È­û³o¦b³c°â¨®²¼¡A¦b¥¿«e¤è¦³¤@¶ô¹q¦r¤½§GÄæ¡A¦b¤W­±¥´µÛ¡G
¡m       [35m [0;1m­[1mn[1m¶[1mR[1m²[1m¼[1mª[1mº[1m½[1mÐ[1mº[1mÉ[1m§[1mÖ[1m¡[1mA[1m¥[1m»[1m¨[1m®[1m¯[1m¸[1m¤[1m§[1m²[1m¼[1m¬[1m°[1m[[1;36m¦[1ma[1m¤[1mU[1m«[1m°[1m-[1m>[1m¥[1mD[1m«[1m°[1;35m][0m  [0m        ¡n

( ´£¥Ü: ¶R²¼½Ð¥ÎBuy Ticket )
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "out":__DIR__"sec8.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/trainman.c" :1,
]));

        setup();
        replace_program(ROOM);

}
