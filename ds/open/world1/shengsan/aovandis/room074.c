// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ªZ¾¹±M½æ©±"NOR);
	set("long", @LONG
§A¬Ý¨ìÀð¤W¤Î±MÂd¸ÌÂ\µÛ¦n¦h¦U¦¡¦U¼Ëªº§ðÀ»ÃþªZ¾¹¡A¬Ý¨ì³o¨Ç¤£¸g
Åý§A¦³·mÁÊªº½Ä°Ê¡A¦pªG»Ý­n¥i¥H¸ò¦ÑÁó¶R§A·Q­nªºªZ¾¹¡C§Aª`·N¨ìÀð¤W
¦³­Ó¥Î¤ìªO°v¦¨ªº§i¥ÜµP(note)¡C
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
            "east" : __DIR__"room062",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}