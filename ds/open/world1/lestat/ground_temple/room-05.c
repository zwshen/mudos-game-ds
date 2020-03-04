#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", "¦a©³¯«·µ¿ò¸ñ") ;
        set( "long", @LONG
´c¯ä¨R¤Ñªº©Ð¶¡¤¤¡A°ïº¡¤F¤HÃþ©M§¯Å]ªº°©Àe¡A¥H¤Î´²¸¨º¡¦aªº
ªø¥Ù¡A¦b°©Àe°ï¤¤¶¡¡A¦³¤@­Ó·t¬õ¦âªº½c¤l¡]box)¡A½c¤lÁôÁôªxµÛ¬õ
¥ú¡A¥i¯à¨ä¤¤ÂÃµÛ¤°»ò¯«¯µªºÄ_ª«¦b¸Ì­±¡C
LONG
);
        set("item_desc", ([ /* sizeof() == 2 */
        "½c¤l"  : "¤@­Ó¬õ¦âªºÄ_½c¡A¤W­±¦³¤@§âÂê¡A§A¥i¥H¸ÕµÛ¼À¶}¥¦¡]break¡^¡C\n",
        "box" :  "¤@­Ó¬õ¦âªºÄ_½c¡A¤W­±¦³¤@§âÂê¡A§A¥i¥H¸ÕµÛ¥´¼À¶}¥¦¡]break¡^¡C\n",
        ]) );
        set("exits", ([ /* sizeof() == 3 */
                  "east" : __DIR__"room-06",
                  "west" : __DIR__"room-04",
                  "south" : __DIR__"room-03",
        ]));
        set("light",0);
        set("no_recall","¯«·µ¤º³¡ªººÏ³õ¾B½ª¤F©Ò¦³ªº¶Ç°e¤O¶q¡C");
        set("no_clean_up", 0);
        setup();
}

void init()
{
add_action("do_pick","break");
}

int do_pick(string str)
{
if(str=="box" || "str" == "½c¤l")
 {
  if(this_player()->query("class1") == "thief")   // checkÂ¾·~¬°¤p°½ 
  {
  write("¾ÌµÛ§A¨­¬°µs¸éªº±Ó¾Uª½Ä±¡A§AÄ±±o³o½c¤l¬O³´¨À¡A¤£¥i¥H¶}¡I\n"); 
  return 1;
  }
  else 
  {
  write("§Aµw¬O¥ÎÆZ¤O¼À¶}½c¤l¡A½c¤l¤¤¼Q¥X¤@¹D¤õµK¿N¶Ë§A«á¡A¤S¦A«×Âó¤W¡C\n");
  this_player()->set_temp("temp/death_type","[[1;31mÄY­«¿N¶Ë­P¦º[0m]");
  this_player()->receive_damage("hp",30+random(80));
  return 1;
  }
 write("§A·Q°µ¤°»ò¡H\n");
 return 0;
 }
}


