#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"¤s¬}¤º"NOR);

 set("long",@LONG
[B[B¦b¤s¬}¤¤, ³s¬}¤fªº¥ú½u³£³z¤£¶i¨Ó¤F, §A¥u¯à¾a¤s¬}±×³»¤Wªº¯}
¬}¶Ç¨Óªº·L®z¥ú½uÁôÁô¬ù¬ùÅG»{¥X¤s¬}¤ºªº´ºª«, ©_©Çªº¬O, ¤s¬}±×³»
¤Wªº¯}¬}¦ü¥G¤£¬O¤ÑµM§Î¦¨ªº, ¥L­Ì¤§¶¡¦ü¥G¦³¤@©w¶ZÂ÷...
LONG
    );
 set("exits",([ "south":__DIR__"birdpill2",
                "west":__DIR__"birdpill4",
                "east":__DIR__"birdpill5",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

