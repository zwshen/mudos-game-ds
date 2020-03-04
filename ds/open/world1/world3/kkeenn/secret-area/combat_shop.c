#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Combat Shop");
        set("long", @LONG
³o¸Ì´N¬O¥¼¨Ó¥@¬É(Future World)±Æ¦W²Ä¤T¦Wªº¯S®í¹D¨ã©±¤F¡I¦bºô
¸ô¤W¦³¤¶²Ð¹L¥¦¡A¦]¬°«O¦³¤@¨Ç¬ì¾Ç®a¶OºÉ¤ß«ä©Ò·Q¥X¨Ó¯«©_ªkÄ_¡A©Ò¥H
¯S§O¦³¦W¡A³o®a©±µ´µL¤À©±¡A¥u¦³¦bªÌ¸Ì¯à¶Rªº¨ì¼Ú ¡C
[ [0;1;36m¬[1mÝ[1m¦[1mC[1mª[1mí[1m [0m]:         [0;1;31mL[1mi[1ms[1mt[0m,
[ [0;1;36m¶[1mR[1m¹[1mD[1m¨[1mã[0m ]:          [0;1;31mB[1mu[1my[0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "east":__DIR__"sec11.c",
     
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/item.c" :1,
]));

        setup();
        replace_program(ROOM);

}
