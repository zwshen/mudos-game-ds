// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"À\\ÆU"NOR);
	set("long", @LONG
³o¸Ì¬O¤@¶¡À\ÆU¡A¥~³¡ªº¸ËæC«ÜÁ¿¨s¡A¤]«Ü§O½o¡A¦³¦UºØ¦n¦Y¦n³Üªº
À\ÂI¡A¨C­Ó¨ì³o¦Y¹Lªº¤H³£¬OÃÙ¤£µ´¤fªº»¡¦n¦Y¡C¦Ó¥B³o¸ÌªºªA°ÈºA«×¤]
¤£®t³á¡C§A¬Ý¨ì¤@­±µP¤l(note)¡C
LONG
	);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss2.c" : 1,
	]));

	set("item_desc", (["note":@NOTE
[1;32m
§G§iµP¤W¼gµÛ:

		buy       ¦V¦ÑÁó¶RªF¦è
		list      ¦ÑÁó·|§i¶D§A³o¸Ì½æ¨Ç¤°»ò
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room107",
	    "west" : __DIR__"room069",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","food");	// À\ÆU

	setup();
	replace_program(ROOM);
}