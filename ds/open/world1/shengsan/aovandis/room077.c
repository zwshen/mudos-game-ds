// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"¨¾¨ã©±"NOR);
	set("long", @LONG
¨¾¨ã¬O§A¦b¾Ô°«¤¤¤£¥i©Î¯Êªº­«­n¸Ë³Æ¤§¤@¡A©¯¹Bªº¡A§A¥¿¯¸¦b¥þ§J
ªL´µ¤j³°³W¼Ò³Ì¤jªº¨¾¨ã©±¸Ì¡C¦³«Ü¦hª¾¦Wªº¨¾¨ã¦b³o¸Ì³c°â¡A§Æ±æ§A·|
³ßÅw¡CÀð¤W±¾µÛ¤@­ÓµP¤l(note)¡C
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
	    "west" : __DIR__"room062",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}