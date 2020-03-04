// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"¦a¹Ï©±"NOR);
	set("long", @LONG
³o¸Ì¦³§JªL´µ¤j³°¤j³¡¤À¦a°Ï¤Î«°¥«ªº¦a¹Ï¡A§Aª`·N¨ì¥|©PªºÀð¤W³£
±¾º¡¤Fºë½oªº¦a¹Ï¨÷¶b¡A¨C¤@´T¦a¹Ï³£¦³¸ÔºÉªº¦a²zÀô¹Ò¤¶²Ð¡A¯uªº¬Oª«
¶W©Ò­È¡C¦pªG¦³»Ý­n§A¥i¥H¦V¦ÑÁó¶R¡C©ÎµÛ¬Ý¬ÝÀð¤Wªº§i¥Ü(note)¡C
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
	    "north": __DIR__"room019",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}