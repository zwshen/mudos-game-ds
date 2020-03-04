#include <room.h>
inherit ROOM;
void create()
{
        set("short", "¦a¤U«°¥¿¤¤¥¡");
        set("long", @LONG
¤ÑªÅªº¥Õ¶³³Q±j¤OªººÏ³õ±j­¢±Æ¦¨ Secret Cityªº§i¥Üª©....

ªF¤è: ©~¥Áªº¤u§@¦aÂI[ [0;1;35mÄ[1mq[1m§[1m|[1m¤[1m§[1m§[1mø[0m ]      ®È«Èªº¥ð¶¢¦aÂI[ [0;1;35m¤[1mQ[1m¤[1mG[1m¤[1mH[1m®[1mÈ[1m©[1m±[1m [0m] 
¦è¤è: ¨¾½Ã¦uÅ@ªÌ³Ì·R[[0;1m [1;35m¨[1m¾[1m¨[1mã[1m©[1m±[1m [0m]        ¬y®ö®È¦æªÌ¤§³B[ [0;1;35m¦[1ma[1m¤[1mU[1m¨[1m®[1m¯[1m¸[0m ]
«n¤è: °Ó¤H³fª«¶°¤¤¦a[ [0;1;35m°[1mÓ[1m«[1m~[1m¥[1mæ[1m¬[1my[1m³[1mB[0m ]    ¤j®aªº¨¾¦u¤u¨ã[ [0;1;35m­[1mx[1m¤[1mõ[1m¤[1m½[1m½[1mæ[1m§[1m½[0m ]
¥_¤è: ®È¤Hªº³Ì·R¦aÂI[ [0;1;35m¯[1mS[1m®[1mí[1m¬[1mö[1m©[1mÀ[1m°[1mÓ[1m©[1m±[0m ]  °ß¤@¯d¦uªº¦Ñ¤H[ [0;1;35m«[1m°[1m¥[1mD[1mª[1mº[1m®[1ma[0m ]
¤W¤è: ¥«¥Á¥~¬ÉÁpµ¸¦a[ [0;1;35m¹[1mq[1mª[1mi[1m¶[1ml[1m§[1m½[0m ] 
¤U¤è: «Äµ£¦Ñ¤H¥ð®§©Ò[ [0;1;35m¶[1mW[1m¯[1mÅ[1mK[1mT[1mV[0m ] 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec4.c",
     "north":__DIR__"sec10.c",
     "east":__DIR__"sec6.c",
     "up":__DIR__"mail.c",
     "west":__DIR__"sec8.c",
     "down":__DIR__"sec13.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
