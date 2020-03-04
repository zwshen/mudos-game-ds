#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Equip Shop");
        set("long", @LONG
³o¸Ì´N¬O¥¼¨Ó¥@¬É(Future World)±Æ¦W«e¤­¦Wªº¨¾¨ã©±¤F¡I¦³¾ú¥vªº
¨£ÃÒ -³o®a©±¤§©Ò¥H¯à¼µ¤U¥h¡A©wµM¦³¥¦ªº¤£¤Z¤§³B¡A­ì¨Óªü¡I¥¿¦]¬°³o
¸Ì¬O¾ú¥v¥j«°¡A©Ò¥H·í¦~³Q¦CºÞ¬°¸T«~ªº¨¾¨ã¡A³o¸ÌÁÙ«O¦³¤@¨Ç©O¡I¡H
[ [0;1;36m¬[1mÝ[1m¦[1mC[1mª[1mí[0m ]:         [0;1;31mL[1mi[1ms[1mt[0m,
[ [0;1;36m¶[1mR[1m¨[1m¾[1m¨[1mã[0m ]:          [0;1;31mB[1mu[1my[0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec9.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/equip.c"   :1,
]));

        setup();
        replace_program(ROOM);

}
