#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIC"µL­«¤O"HIW"¬ì§Þ¨«´Y"NOR);
  set ("long", @LONG
¤@¨ì³o­Ó¤u§@«Ç«eÆU¡A´N¬Ý¨ì¤F¥_¤è¦³¤@±ø°ª¬ì§ÞªºÀG¹D¡A
ªø«×²`¤£¨£©³¡AÀG¹D¤¤§Gº¡¤F³\¦hºë±Kªº»ö¾¹¡A¤£ª¾¹D¦³¤°
»ò¥Î³~¡A®ÇÃäªº¤p¿Ã¹õÅã¥ÜµÛ©¹¥_¥i¥H³q¨ì¤u§@«Çªº¤¤¤ß¦a
±a
LONG);

  set("exits", ([ 
  "north" : "/u/h/hack/room01.c",
 
]));
  set("valid_startroom", 1);
  set("light",1);
  setup(); 


  replace_program(ROOM);
}
