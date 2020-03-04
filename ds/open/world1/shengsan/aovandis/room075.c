// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"¹D¨ã©±"NOR);
	set("long", @LONG
³o­Ó°Ó©±±Mªù´£¨Ñ¦UºØ®È¦æ©Î¥­®É©Ò­n¥Î¨ìªº¤u¨ã¤Î¹D¨ã¡A¡y¤u±ýµ½
¨ä¨Æ¡A¥²¥ý§Q¨ä¾¹¡C¡z¬O³o®a©±­±¦ÑÁó³Ì±`Á¿ªº¤@¥y¸Ü¡C§A·|»Ý­n¥¦­Ìªº
¡CÀð¤W¦³­Ó§i¥ÜµP(note)¡C
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
	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room063",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}