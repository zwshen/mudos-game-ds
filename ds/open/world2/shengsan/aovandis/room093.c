// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ÂÅÂÅ»È¦æ"NOR);
	set("long", @LONG
³o¶¡»È¦æ¬Û·íªº¦³³W¼Ò¡A¼ä²bªºÀô¹Ò«ÜÅý¤H¯«²M®ð²n¡C»È¦æ­û»{¯uªº
¦b¬°«È¤áªA°È¡A¬°ªº¬OÅý»È¦æ¯à¶V°µ¶V¤j¡A«È¤á¶V¨Ó¶V¦h¡C¦³¤@¶ôªO¤l(board)
¤W­±¦³¤½§iªºªF¦è¡A¤]³\§A¸Ó¬Ý¤@¬Ý¡C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room088",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss3.c" : 1,
	]));

	set("item_desc", (["board":@NOTE
[1;32m
§G§iµP¤W¼gµÛ:

	deposit		¶}¤á¡G¦s¿ú
	withdraw	»â¿ú

[m
NOTE
        ]) );

	set("no_clean_up", 0);
	set("valid_startroom",1);
	set("light", 1);
	set("room_type","bank");	// »È¦æ¿ú²ø

	setup();
	replace_program(ROOM);
}