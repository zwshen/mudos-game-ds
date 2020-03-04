#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"¤ì¼Î°}¤¤"NOR);

 set("long",@LONG
 
  §AÄ±±o¥|©P³Q¤ì¼ÎÀ½ªº´«¤£¹L®ð¨Ó, ¬J¤§µo²{³o¬O§Aªº¤ß²z§@¥Î,
¥i¨£¹ï§A¤w¸g·P¨ì¤@©wµ{«×ªº¤ß·W·N¶Ã¤F....§A¤ß¤¤¤£¸T§Æ±æ·P§Ö¨«
¥X³o¤@­Ó¥O¤H¤ß·W¤F¦a¤è....³o¸Ìªº[1;33m¦a¤W¦³¥|­Ó¸}¦L[0m...

ùþ¢­                                                 ¢¬ùþ
ùþ¢y¡Ä                                             ¡Ä¢jùþ
ùþ¢y :¢j                                         ¢y: ¢jùþ
ùþ¢y :¢j                                         ¢y: ¢jùþ
ùþ¢y¡Ã                                             ¡Ã¢jùþ
ùþ¢¬                                                 ¢­ùþ

LONG
    );
 set("exits",([ "west":__DIR__"wood3.c",
                "east":__DIR__"wood1.c",
                "north":__DIR__"wood2.c",
                "south":__DIR__"wood5.c",
    ]));

 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
