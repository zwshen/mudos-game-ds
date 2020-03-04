#include <path.h>
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"¹Ú¤Û°Ï°ì·s¤â±Ð«Ç"NOR);

set("long", @LONG

[1;31m                  ¢d¢d¢d¢d¢d¢d¢d¢d¢d¢d¢d¢d¢d¢d¢d
                ¢¨ùþùþùþùþùþùþùþùþùþùþùþùþùþùþùþ¢©
             ¢ªùþùþùþùþùþùþùþ[m[47;30mÅwªï»YÁ{[1;40;31mùþùþùþùþùþùþùþ¢«
[0m¢u¢q¢q¢q¢q¢q¢q¢q¢q[31m¢m¢n[1;33m¢z¢w¢w¢w¢{¢x¢z¢w¢w¢w¢{[0;31m ¢m¢n[m¢q¢q¢q¢q¢q¢q¢q¢q¢t
¢u¢r¢r¢r¢r¢r¢r¢r¢r[31m¢m¢n[1;33m¢x      ¢x¢x¢x      ¢x[m[31m ¢m¢n[m¢r¢r¢r¢r¢r¢r¢r¢r¢t
[1m¢¥[36m  .[32m"[37m   "    '[m[31m   ¢m¢n[1;33m¢x      ¡³¢x¡³      ¢x[m[31m ¢m¢n[1;37m'®È«Èª`·N!!     ¢§
¢¥          . "[0;31m   ¢m¢n[1;33m¢x      ¢x¢x¢x      ¢x[0;31m ¢m¢n[1;37m ½Ð¤Å³æ¿W¥~¥X   ¢§
¢¥ "    .[35m"[32m    `[31m   ¢m¢n[33m¢|¢w¢w¢w¢}¢x¢|¢w¢w¢w¢}[31m ¢m¢n[37m,¥H§K¤£´ú!      ¢§
¢r¢w¢w¢w¢w¢w¢w¢w[31m¢yùþ¢o[33m¢w¢w¢w¢w¢w¢r¢w¢w¢w¢w¢w[31m|ùþ¢o[37m¢w¢w¢w¢w¢w¢w¢w¢w¢r[m

  Åwªï¥[¤J¹Ú¤Û¤C°ì!! §A¥Ø«eªº¦ì¸m¬O¦b¹Ú¤Û®ÈÀ]¤¤ªº·s¤â±Ð«Ç.
	
  §A¹ï©óªÅ¤¤¦³³oºØ¦a¤è·P¨ìÅå©_, §AÀôÅU¤F§Aªº¥|©P, µo²{³o¸Ì°£
¤F´X¥»¥j®Ñ(books)©M¤@­ÓÅK»sªº§i¥ÜµP(sign) ¥H¥~¥u¦³¤@¨ÇÄð»s®à
´È, §A¥J²Ó¬Ý¤F¤@¬Ý, ÅãµM³o¸Ì¬Oµ¹ªì¥X­TÃfªº·s¤â±Ð¾Ç¥Îªº¤]³\§A
¥i¥H¬Ý¬Ý(look©Îl)§i¥ÜµP©Î¥j®Ñ, ¬Û«H§A·|¦³©Òµo²{ªº....

[ ´£¥Ü: ­n¬Ý³o¸Ìªº®Ñ´N¿é¤J look books ©Î¬O l books ]

LONG
    );
 set("exits",([
                "east":__DIR__"school2.c",
    ]));
 set("item_desc",([
        "books":"§A¬Ý¤F¬Ý³o¨Ç¹Ð«Ê¤w¤[ªº®Ñ, µo²{¥¦­Ì·ÓµÛ½s¸¹±Æ¦C, §A·QÀ³¸Ó±q²Ä¤@
¥»(book_1)¶}©l¬Ý°_.\n",
        "sign":"³o­±ÅK»sªº§i¥ÜµP¼gµÛ:!! Åwªï¨Ï¥Î·s¤â±Ð«Ç !!.\n",
        "book_1":@BOOK1

  ³o¤G¥»®Ñ¥D­n¬O­n§i¶D§A¤@¨Ç·s¤âÀ³¸Óª¾¹Dªº±`ÃÑ, ­º¥ý, Ds¸ò¨ä
¥¦ªºmud¤@¼Ë, ·s¤â°È¥²­n¥ý¬Ý¤@¬Ý§Ú­Ìªº³W«h (help rules), ¦]¬°
§A©Òª±ªºmud¥i¥Hªº¨Æ¶µ¥i¯àDs¤£¥i¥H,©Ò¥HÅª³W«h¥i¥HÁ×§K§AµL§Î¤¤
¥Ç¿ù, ¬Ý¨ì³o¸Ì, §AÀ³¸Ó¤w¸gª¾¹D³o¥»®Ñ¬O­n±Ð§A¦p¦ó¨Ï¥Îhelp, §A
¥i¥H¦b´¶³q±¡ªp¤Uª½±µÁä¤Jhelp, ±µ¤U¨Ó·|¥X²{¤@¨Çhelp¥DÃD, §A¥i
¥H¥´help xxx¦A¦hª¾¹D¤@¨Ç¸Ô±¡, ¦n¤F..³o¤@¥»®Ñ±Ð§A¦p¦ó¥Îhelp, 
´N¨ì³o¸Ì, ±µ¤U¨Ó§A´N¥i¥H¬Ý²Ä¤G¥»®Ñ(book_2)¤F.¯¬§A¤@¸ô¶¶­·...

BOOK1
,
        "book_2":@BOOK2
        
  ¦n¤F, ³o¤@¥»®Ñ¬O­n±Ð§A¦p¦ó©M¨ä¥¦ªºª±®a¥æ½Í, ­º¥ý§A¥i¥H¨Ï¥Î
<tchat> ¸ò¨ä¥¦©Ò¦³ª±®a¥æ½Í, ¤]´N§A¬O§A»¡ªº¸Ü©Ò¦³ª±®a³£·|¬Ý¨ì
, ±µµÛ§A¤]¥i¥H¨Ï¥Î<say> ¨Ó¸ò¸ò§A¦b¦P¤@®æªº¤H¥æ½Í, ¥u¦³§A³o®æ
ªº¤H¤~¬Ýªº¨ì, <tell [ª±®a¦W]>¥i¥H¨Ï§Aªº°T®§¥u³Q³o­Ó¤H¬Ý¨ì, 
 <shout> ªº¨Ï¥Î°ò¥»¤W©M <tchat> ®t¤£¦h, ¤£¤Ó«ØÄ³·s¤â¨Ï¥Î....
 ok! ³o¥»®Ñ´N¨ì¦¹µ²§ô....§Æ±æ¹ï§A¦³©ÒÀ°§U....

BOOK2
,
        ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();

}

