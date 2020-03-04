// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ªA¹¢ºë«~©±"NOR);
	set("long", @LONG
Ãoµ¡¤W¯¸µÛ¤@¨â­Ó¼Ò¯S¨à¡A¨­¬ï¬üÄRªºªA¸Ë¡AÀ¹µÛ«GÄRªº¹¢«~¡C¤@®Ç
ªº©±­û¥¿¦b¤Ñªá¶Ã¼Y¦a¬°«È¤á±À¾P©±¤ºªº©Ò¦³ªA¹¢ºë«~¡C©±¤ºªº¤ÑªáªO¦Q
µÛ¤@­Ó­Ó°{«Gªº¤ô´¹¡A¦³ÂÅÃC¦â¡AºñÃC¦â¡A¯»¬õ¦âµ¥µ¥¡C
Àð¤W¦³­ÓµP¤l(sign)
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room101",
	    "west" : __DIR__"room090",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss4.c" : 1,
	]));

	set("item_desc", (["sign":@NOTE
[1;32m
§G§iµP¤W¼gµÛ:
[1;33m
		buy       ¦V¦ÑÁó¶RªF¦è
		list      ¦ÑÁó·|§i¶D§A³o¸Ì½æ¨Ç¤°»ò

[m
NOTE
        ]) );

	set("no_clean_up", 0);
	set("valid_startroom",1);
	set("light", 1);
	set("room_type","sell");	// °Ó©±(¥u¯à¶RªF¦è)

	setup();
	replace_program(ROOM);
}