#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "¯«°ó");
        set("long", @LONG
³o¸Ì¬O¶³ºÝªº³Ì§ÀÃä , ©¹¤U¤@±´ , Â÷¦a¸U¤Ø , ©ïÀY¤@±æ 
, ¯E¤ë¤d¨½ , ¥u¨£³o¸Ìªº©P³ò , ³òÂ¶µÛÁ¡Á¡ªº¶³Ãú , ¦³ºØ¯«
¸t¤£¥i«I¥Çªº·PÄ± , ¦pªG§A¦b³o¸Ì°µ¤F¤°»ò[0;7;31mÃ[7ma[7m¨[7mÆ[0m ,¥i¯à·|¾D¨ü
¨ì¤ÑÄþ ¡C ³o¸Ì¦³¤@´LÀJ¹³ ¡C

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room1",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"statue" : 1,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

