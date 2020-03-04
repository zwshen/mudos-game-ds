// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"¹q¸£½æ³õ"NOR);
	set("long", @LONG
ªï­±¦Ó¨Óªº´N¬O¤@±i±i¶K¦bªù¤fªº®ü³ø¡A¬Á¼þÂd¤WÂ\µÛ¤@Å|Å|ªº¹q¸£
³ø»ù³æ¡A¬Á¼þÂd¤º³¯¦CµÛ¦U¦¡ªº¹q¸£°Ó«~¡C§A¬Ý¨ì´X­Ó¤H¬°µÛ¤@­Ó¤p¶ê®à
¡A¦ü¥G¥¿¦b°Q½×»ù¿ú¡C³o¸Ì¬O¥«¤º¦³¦Wªº¹q¸£½æ³õ¡A¦b³o¸Ì§A¥i¥H¶R¨ì§A
·Q­nªº°ª¬ì§Þ¹q¸£²£«~¡CÀð¤WÁÙ±¾µÛ¤@­Ó§i¥ÜµP(sign)¡C

LONG
	);
	set("item_desc", (["sign":@NOTE
[1;36m
§G§iµP¤W¼gµÛ:
[1;32m
		buy       ¦V¦ÑÁó¶RªF¦è
		list      ¦ÑÁó·|§i¶D§A³o¸Ì½æ¨Ç¤°»ò
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room062",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss5.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","sell");
	setup();
	replace_program(ROOM);
}