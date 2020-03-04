#include <path.h>
#include <login.h>
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"·s¤â±Ð«Ç¤G¼Ó"NOR);

 set("long",@LONG

  ®¥³ß§A²×©ó³q¹L¤F°g®c, ·s¤â±Ð«Ç¤w¸g¨S¦³¤°»ò¥i¥H±Ð§AªºªF¦è¤F
, §Æ±æ§A¤w«á¯à°÷¦æ«L¥M¸q, ¿í¦uDsªº³W«h, ¦¨¬°¤@­Ó¥O¤H·q¨Øªº¦n
ª±®a! ¤Á°O! ¤Á°O! «x? §A¬Ý¨ì³Ì«á³oÃäÁÙ¦³¶ôªO¤l([1;35mboard[0m)¡C
                                                  ¢¬
¡Ä¡Ä                                    ¡Ä¡Ä¡Ä¡Ä¢¬
" ¢y¢­¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¡Ä¢¬¢j'    "¢j¢¨
: ¢y¢y=" '                         "" ¢j¢j  "  :¢j¢i
= ¢y¢y==-  "           "'           =-¢j¢j     =¢j¢i
: ¢y¢¬¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¢­¢j   -==¢j¢i
¡Ã¡Ã                                    ¡Ã¡Ã¡Ã¡Ã¢­¢i
                                                  ¡Ã¢j
                                                    ¢­

LONG
    );
    
 set("exits",([ "out":START_ROOM_PAST,
    ]));
 set("item_desc",([
"board":@BOARD

§A¥J²Óªº¬Ý¤F¬Ý§i¥ÜªO, µo²{¤W­±³o¼Ë¼gµÛ:

  °O±o¦h¬Ýhelp, ¦hÅ¥¦Ñª±®a»¡ªº, ÂÔ°O¡u§V¤O§äµª®×, ¤£­n°Ýµª®×¡v
¤è¯àÅé·|¥Xª± MUDªº¦¨´N·P! ¤°»ò? ·Q­n³t¦¨°Ú....¦³¨Ç¤H¦n¤ßªºµ¹
¤F¤@ÂI´£¥Ü, §A´N¬Ý¬Ý§a!


¥j¥NªF¤èªº³¡¥÷:

	¡i¤K·¥ªù¡j      Â¾·~: ªZªÌ 
	Ãþ§O: ªì¯Å¥Î®±, µ¥¯Å²¤°ª«á¥i½mºjªk
	ªù¬£¦aÂI: ±q´Â¤Ñ¼Óªþªñªº¤j¤ô¬û©¹¦èÃä¨«¥h§ä¬Ý¬Ý§a..
	¤Jªù´£¥Ü: §ä¨ì§õ®Ñ¤å«á¥´:<join ¤K·¥ªù>, §õ®Ñ¤å«Ü­n­±¤l
                ¥s§A»¡¤@¥yÃÙ´­¤K·¥ªùªº¸Ü, Å¥»¡§õ®Ñ¤å¦³°e±i®Ñ
                ªkµ¹©s§ø§øªø©s¬î¹A, ´N±¾¦b§øªø®a, ©Î³\......
      
    ¤°»ò°Ú? ¤K·¥ªù§AÁÙ¤£²n½m? ¦n§a, ¦A§i¶D§A¤@ÂI, ½Ð¬Ý([1;35mboard2[0m).

BOARD
,
"board2":@BOARD2

  ¦n§a, ´N¦Aµ¹§A¬Ý¤@¨Ç´£¥ÜÂP....¦A¤£·|§Ú¥i¤£À°§A°Õ!
  
	¡i¯«ªZ±Ð¡j	Â¾·~: ¹D¤h
	
	Ãþ§O: ¥Hªk³N¬°¥D­n, ¼Cªk¬°»²§U§ðÀ»
	¤Jªù´£¥Ü: ¥ý¨«¨ì¤Ñ«°¥_¤èªº¤Ñ¦À¡u¤W­±¡v, ¤£·|¨«? ¦Û¤v
		  ·Q¿ìªk. ¥h½Õ¬d¤@¤UÂr¥¬«á­±¥Û¾À¤ºªº¥È¾÷§a..
		  ¥~­±¦³­Ó¶Â¦ç¦Ñ¤H¤@ª½·Qª¾¹D¥Û¾À¤ºªº¥È¾÷, §A
		  ´NÅý¥Lª¾¹D¥L´N·|°ª¿³ªºµ¹§A¤@¶ôªFªF..µM«á¥h
		  ¤Ñ«°ªº«n¤è....¤§«á¦Û¤v°µ!
	  
    	¡°¨ä¥L­«­n½u¤W»¡©ú½Ð¥Î ¡i[1;32m help [0m¡j «ü¥O. 
    	¡°³Ì·sª©ªº·s¤â«ü«n¬O ¡i[1;33m help start_1 [0m¡j
	  
	[1;36m ¦n°Õ! ¯¬§A¦bDSªº«_ÀI¥Í²P¤@¤Á¶¶§Q![0m

					     - DS ¹Î¶¤·q±Ò 1999-
BOARD2
,
]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}

void init()
{
	this_player()->set("quest/not_newbie",1);
	this_player()->delete("newbie");
}
