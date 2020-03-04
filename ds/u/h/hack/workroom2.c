#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", RED"´cÆF"HIW"¤u§@«Ç"NOR);
  set ("long", @LONG
¤@¨ì³o­Ó¤u§@«Ç¡A´N¬Ý¨ì³o¸Ì¦³µÛ¤@±i¤j®à¤l¡A»P¤@­ÓÂd
¶Kº¡¤F³nµwÅéªº®ü³ø¡A«á­±¦³µÛ¤@¥x§ù¤ñ­µÅT¡A¥¿©ñµÛÖq
Öqªº­µ¼Ö¡A¤@¨ì³o¸Ì´N·PÄ±¨ì¥Lªº¥D¤H¤@©w«~¨ý°ª¶®³á.^^

LONG);

  set("exits", ([ 
  "west" : "/u/h/hack/room01.c",
 
]));
 
  set("light",1);
  setup(); 


  replace_program(ROOM);
}
