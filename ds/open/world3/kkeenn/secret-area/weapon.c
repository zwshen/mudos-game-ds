#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Weapon Shop");
        set("long", @LONG

¥|©P³ºµM¤@­Ó¤H³£¨S¦³¡A¥u¦³¤@¥x¥j¸³¶¥¯Åªº¾÷¾¹¤H¦b§V¤O¦a¦V§A±À
¾P¦Û¤vªº°Ó«~¡C
[[0;1;35m¬[1mÝ[1m³[1mf[1m¦[1mâ[0m] :              [0;1;5;31m [0;1;31mL[1mi[1ms[1mt[0m,
[[0;1;35m¶[1mR[1mª[1mF[1m¦[1mè[0m]  :              [0;1;31m [1mB[1mu[1my[0m,
P.S
[0;1;32m¥[1m»[1m°[1mÓ[1m©[1m±[1m¤[1m£[1m±[1mµ[1m¨[1mü[1m½[1mæ[1mª[1mF[1m¦[1mè[1m,[1m [1m½[1mÐ[1m¨[1mì[1me[1ma[1ms[1mt[1m,[1m [1mn[1mo[1mr[1mt[1mh[1m,[1m [1me[1ma[1ms[1mt[1m¥[1mh[1m½[1mæ[1m³[1mf[1mª[1m«[1m,[1mÁ[1mÂ[1mÁ[1mÂ[1m¦[1mX[1m§[1m@[0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
    "east":__DIR__"sec2.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/weapon.c"   :1,
]));

        setup();
        replace_program(ROOM);

}


