#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"¤s¬}¤º"NOR);

 set("long",@LONG
¦b§A¦n©_¤ßªº¤Þ»¤¤U, §A¥ç¨B¥çÁÍªº¨«¨ì¤s¬}¤¤, ¤s¬}¤¤°£¤F¬}¤f
¤Î¤s¬}±×³»¤Wªº¤p¬}¥~³z¤Jªº·L·L«G¥ú¥~, ¨S¦³¨ä¥Lªº¥ú·½, §A¥u¯à¾a
³o¤@ÂIÂI·L®zªº¥ú·½¦b¤s¬}¤¤Á}Ãøªº¨«µÛ, §A¥i¥H·P¨ì¦b§A¨C½ñ¥X¤@¨B
[B, ³£¦b¤s¬}¶Â·t³B³y¦¨¤@°}ÄÌ°Ê, §A¥i¥H·PÄ±¨ì¥Û¾À¤£´M±`ªº²ÊÁW, ¦b
³o¸Ì, ®É¶¡¬O¨º»òªºªø, ·PÄ±¤W, ¶Â·t¤¤¦n¹³¦³¤@ÂùÂùªº²´·ú¥¿¦b°½°½
ªº¬ÝµÛ§A...
LONG
    );
 set("exits",([ "out":__DIR__"birdpill",
                "north":__DIR__"birdpill3",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

