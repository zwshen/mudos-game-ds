// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"¯]Ä_©±"NOR);
	set("long", @LONG
§A¦b¤@¶¡¯]Ä_©±¸Ì¡AÂd¤l¸Ì¦³¦n¦hªº¶Q­«Ä_¥Û¤Î¦W¶Q¸Ë¹¢«~¡A«°¸Ìªº
©~¥Á³£·|¦b³o¶R¨ì¥L­Ì©Ò³ß·Rªº¦ÕÀô¡B¶µÁå¡B§Ù«üµ¥µ¥º}«Gªº¹¢«~¡AºØÃþ
Ác¦h¡A¥Ø¤£·vµ¹¡CÀð¤W¦³­Ó§G§iµP(note)¡C
LONG
	);
	set("item_desc", (["sign":@NOTE
[1;32m
§G§iµP¤W¼gµÛ:

		buy       ¦V¦ÑÁó¶RªF¦è
		list      ¦ÑÁó·|§i¶D§A³o¸Ì½æ¨Ç¤°»ò
		value     ¦ÑÁó·|§i¶D§A½æ³o¥óªF¦è¥L·|µ¹§A¦h¤Öª÷¹ô
		sell      §â¬Y­ÓªF¦è½æµ¹¦ÑÁó
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room012",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}