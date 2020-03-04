// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"Å]ªk¥Î«~©±"NOR);
	set("long", @LONG
±MÂd¸Ì³¯¦CµÛ¬Ã¶QªºÃÄ¤ô¡A³o¨ÇÃÄ¤ô¥i¤£¬O´¶³qªºÃÄ¤ô¡A¥¦­Ì³£¦³¦U
ºØ¤£¦PªºÅ]ªk®ÄªG¡C¦b¥~¨D¥Í®Éµ´¹ï­n·Ç³Æ­Ó´X²~ÃÄ¤ô¥H³Æ¤£®É¤§»Ý¡C§A
¬Ý¨ìÀð¤WÄa±¾µÛ¤@­Óº}«Gªº§i¥ÜµP(note)¡C
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
            "east" : __DIR__"room064",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}