// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ÄÑ¥]©±"NOR);
	set("long", @LONG
¦pªG§A­n¦Y¦Y³Ì¨ã¯S¦âªºÄÑ¥]¡A¨º»ò§A¨Ó¹ï¦a¤è¤F¡C³o¬O¤@¶¡¥H³Ð·N
¤Î¬ü¨ý±¾«ÓªºÄÑ¥]©±¡A®Æ¦n¹ê¦b¡A¦Ó¥B»ù¿ú¤]¬Û·íªº«K©y¡C«°¸Ìªº©~¥Á³£
·|¦b³o¶R¥L­Ì·R¦YªºÄÑ¥]¡A¨C·í¦³¼y¥Í®É¡A³o¸Ì©Ò°µ¥Xªº³J¿|¤]¬O¥L­Ìªº
³Ì·R¡CÀð¤W±¾µÛ¤@­Ó§i¥Ü(note)¡C
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
            "west" : __DIR__"room070",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}