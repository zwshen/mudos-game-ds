// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"¿}ªG«Î"NOR);
	set("long", @LONG
³o¶¡¿}ªG³y«¬ªº°Ó©±¡A¬O¶¡±Mªù³c½æ¹s¼L¡B¤pÂI¤ßªº°Ó©±¡A©±¤º¤@±Æ
±Æ¾ã»ôªº­¹ª«¬[®ÇÁ`¬O¦³«È¤H¦b¨º¬D¿ï³ßÅwªº¹s¼L¡C©±­û«C¬K¬¡¼âªº¥´§ê
¡AµÛ¹êÅý¤H¦³ºØ¿Ë¤Á·P¡C¦bÀð¤W±¾µÛ¤@­ÓµP¤l(sign)¡C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room090",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss4.c" : 1,
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
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","sell");	// °Ó©±

	setup();
	replace_program(ROOM);
}