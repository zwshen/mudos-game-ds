#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"·s¤â±Ð«ÇªÅ¤¤®x°|"NOR);

 set("long",@LONG
 
       ¢z¢s¢{          ¢z¢s¢{                  ¢j
       ¢u¢q¢t          ¢u¢t¢x                  ¢j
       ¢|¢r¢}          ¢|¢r¢}[1;32m¡\[m   ¡Å¡Å         ¢j
¡Å                         [1;32m¡ì[1;31m¡¯[1;32mùû[m ¢©  ¢­       ¢j
¢¨¡Å    ¢z¢w¢w¢w¢{          [1;32m/_|_*[m ¢i¢©  ¢­___O_¢j
¢«¢¨¡Å¡Ã¢x[1;33m½Ð¤W¼Ó[m¢x¡Ã¡Ã¡Ã¡Ã¡Ã \_/¡Ã¢ª¢i¢©  ¢­/Y\¢­
¡Ã¢«¢¨¡Å¢|¢w¢s¢w¢}                  ¢ª¢i¢©  ¡Ã¡Ã¡Ã¡Ã¢­
  ¡Ã¢«¢¨    ¢r                        ¢ª¢i¢i¢i¢i¢i¢i¢i
    ¡Ã¢«                                ¢ª¢i¢i¢i¢i¢i¢i
¡Ã¡Ã¡Ã
  §A¨«¶i¤F¥t¤@¶¡©Ð¶¡, µo²{³o¸Ì¬O¤@³BªÅ¤¤®x°|, ¨ì³B³¾»yªá­», 
§A¬Ý¨ìªºªá¥cÅãµMªá´Á¤£¦P, ¥Ñ¦¹¥i¥H¬Ý¥X³o¸Ì¦ü¥G¨S¦³¥|©u¤§¤À,
§A¦A¥J²Ó¤@¬Ý, µo²{¦bªáÂO(flowers)¶¡¤@®Ú¬ð°_ªº¤ìÀY(wood)¤W­±
¼g¤F¨Ç¦r, §A¤@·Q¤F·Q.... ºâ¤F, ¥ý¬Ý¬Ý§a....

LONG
    );
 set("exits",([ "west":__DIR__"school1.c",
                "up":__DIR__"school3.c",
    ]));
 set("item_desc",([
 	"flowers":"§A¬Ý¨ìªáÂO¤¤¦³¤@®Ú¤ìÀY(wood)..\n",
        "wood":@WOOD
        
  §A¬Ý¤F¬Ý³o®Ú¤ìÀY, µo²{­I­±¬O¥­ªº, ¤W­±¼gµÛ: ¾Ô°«§Þ¥©, ....
«z! «á­±ªº¦r¬Ý¤£²M¤F....«ç»ò¿ì©O? ¸Õ¸Õ¬Ý¥J²ÓÀË¬d(search wood)
¤@¤U§a!
        
WOOD
,
        "book":@BOOK
        
  ³o¥»®Ñ¬O­n±Ð§A¦p¦ó¾Ô°«, ¤]¬O¤Ñ¯«³Q§A¸Û¤ß·P°Ê¦Ó±¼¤Uªº®Ñ..§Æ
±æ§A¦n¦n¬Ý¤@¤U. ­º¥ý¤U search flowers ³o­Ó«ü¥O. ·|¶]¥X¤@°¦½¹
½º, ¹ï¥¦¤Ukill«ü¥O, ¨º´N¬O¾Ô°«ªº¹êªp, ¾Ô°««eÀ³¥ý¥ÎconsiderÅ²
©w¤@¤U¼Ä¤H, ¦A¶}¾Ô, ¨º¸U¤@¤£©¯°}¤`«ç»ò¿ì©O? §A¦º«á·|¨ì¤@­Ó¦³
¨â­ÓÀJ¹³ªº¦a¤è....¨ä¤¤¤@­Ó¬O¥Í©R¤§¯«, ¤@­Ó¬O¦º¤`¤§¯«, Áo©ú¦p
§A, À³¸Óª¾¹D­n«ô­þ¤@­Ó§a!?¤Ï¥¿¿ù¤F¦A¸Õ¹À...., ¹ï¤F, ±þ¦º¼Ä¤H
«á¤£­n§Ñ°O©^Äm(sac)¥Lªº«ÍÅé(corpse)³á!¦ý¥i§O·m§O¤H±þ¦ºªº¤Hªº
«ÍÅé³á...

[´£¥Ü: ¶}¾Ô«e¥ý¿é¤J<wimpy 50>¨Ó³]©w¦Û°Ê°k¶]¬O¤ñ¸û¦w¥þªº°µªk]
[´£¥Ü: ¹J¨ì¥iºÃªº¦a¤è¤£§«¨Ï¥Î search here ¥J²Óªº·j¬d¤@¤U§a!]

BOOK
,
    ]));
    
 set("light",1);
 set("no_clean_up", 0);
 setup();
}

int do_search(object me,string arg)
{
        object butterfly;
	if(arg == "flowers" && !present("butterfly", this_object()))
        {
                if(me->query("find_butter"))   //change by Kkeenn because Legand©ñsearch robot¶Âexp
                {
                        message_vision("$N¥J²Óªº¦bªáÂO¤¤´M§äªF¦è, ªáÂO¶¡¬ðµM­¸¥X¤@°¦³Q¯«¤O±j¤Æ½¹½º¡C\n\n",me);
                        butterfly=new(__DIR__"npc/butterfly2.c");
                        butterfly->move(__DIR__"school2.c");
                        me->set("find_butter",1);
                        return 1;
                }
                if(!me->query("find_butter"))
		{
        		message_vision("$N¥J²Óªº¦bªáÂO¤¤´M§äªF¦è, ªáÂO¶¡¬ðµM­¸¥X¤@°¦¤p½¹½º¡C\n\n",me);
			butterfly=new(__DIR__"npc/butterfly.c");
			butterfly->move(__DIR__"school2.c");
                        me->set("find_butter",1);
			return 1;
		}
	}
	if( arg == "wood")
	{
		tell_object(me,"´N¦b§A¥¿­n¥J²ÓÀË¬d¤ìÀY®É..©¿µM, °Ô! ªº¤@Án, ¤@¥»®Ñ(book)±¼¤F¤U¨Ó..\n¬Ý¬Ý¤W­±¼g¨Ç¤°»ò§a(look book).\n");
		return 1;
	}
	return 0;
}
