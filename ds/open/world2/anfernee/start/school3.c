#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"·s¤â±Ð«Ç¤G¼Ó"NOR);

 set("long",@LONG


[44m                                                        [m
[30;44m       ¡Ë                           ¢l¢©        ¡Ë      [m
[30;44m                    ¡Ë           ¢¨ ¢l¢i¢©              [m
[1;33;44m      ¡´[0;30;44m                       ¢¨¢i ¢l¢i¢i              [m
[30;44m                             ¢¨¢i¢i ¢l¢i¢i              [m
[30;44m                           ¢ª¢f¢f¢i¢i¢i¢f¢f¢h¢«         [m
[1;34;44m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i[m

  §A¦V¤Wª¦, ¦A¤@¦¸Åå²§©ó³o­Ó±Ð«Ç¬[¦bªÅ¤¤ªº°­©ò¯«¤u, §Aµo²{§A
ªº¥|©P¬O¤@¨Ç¤ì¼Î, ¨ä¤¤¦³¤@­Ó¤W­±¶K¤F¤@±iªx¶Àªº¦Ï¥Ö¯È (paper)
, §A¦P®É¤]µo²{³o¸Ìªº­·´º·¥¦n, ¬Æ¦Ü¥i¥H¬Ý¨ìÅb¤l¾ô, ´Â¤Ñ´òµ¥¦W
³Ó´ºÆ[ , ¤£ºÞ«ç»ò¼Ë, ÁÙ¬O¥ý¬Ý¬Ý¯È¤W¼g¤F¤°»ò§a! 

LONG
    );
 set("exits",([ "north":__DIR__"wood1.c",
 		"down":__DIR__"school2.c",
    ]));
 set("item_desc",([
	"paper":@PAPER
	
  ³o±i¯È¤W¼gµÛ: ¦b³o­Ó¥@¬É¤¤, ¦³¨Ç¦a¤è¥R¥¸µÛ°g®c, °g®c¤@¯ë¨Ó
»¡³£¦³¤@©wªº¨«ªk, ¦p: ©¹¥_¨«´X¨B, ©¹¦è¨«´X¨Bµ¥....¸U¤@¯uªº¨«
¤£¥X¥h, ¤]¥i¥H¥Î< [1;33mrecall start[0m >¦^¨ì¹Ú¤Û®ÈÀ]....§Ú­Ì¬°¤F¨Ï§A
¥i¥H§ó¼ô±x¦p¦ó§ì¨ì³W«ß, À³¦¹¦b³o¸Ì©¹¥_´N¦³¤@­Ó°g®c, §Æ±æ§A¦­
¤é¼ô±x¦p¦ó§ì¨ì³W«ß!

[ µù: Ãö©órecallªº¥Îªk, ½Ð¥´ help recall ¬Ý¬Ý. ¦³¤À¤TºØ³á!! ]

PAPER
,
    ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
