// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"¶W¯Å°Ó©±"NOR);
	set("long", @LONG
§A¨«¶i¤F¤@¶¡¶W¯Å«K§Q°Ó©±¸Ì­±¡A§Aµo²{³o¸Ì½æªºªF¦è«ÜÂø¡A¤£
¹L«o³£¤Q¤À¹ê¥Î¡A¦b³o¸Ì§A¥i¥H¶R¨ì¤@¨Ç¤é±`¥Î«~©M¤@¨Ç¦çª«¡C
Àð¤WÁÙ±¾µÛ¤@­Ó§i¥ÜµP(sign)¡C

LONG
	);
	set("item_desc", (["sign":@NOTE
[1;36m
§G§iµP¤W¼gµÛ:
[1;32m
		buy       ¦V©±­û¶RªF¦è
		list      ¬Ý¬Ý³o¸Ì¦³½æ¨Ç¤°»ò
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room063",
	    "south": __DIR__"room066",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss6.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","sell");
	setup();
	replace_program(ROOM);
}