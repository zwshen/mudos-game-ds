// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"Â¾·~¤¶²Ð©Ò"NOR);
	set("long", @LONG
ªø®à¤l¤Wªº¤å¥ó¦³¨Çªº­â¶Ã¡A¤@¦ì¤¤¦~°ü¤H¥¿¦b¿ì¤½¡C§N®ð¥R¥¸³o¾ã
­Ó©Ð¶¡¡A¥ªÃäÀð¾À¦³­Ó¤å¥ó¾ã²z²°(box)¡A¬Ý°_¨Ó¸Ì­±À³¸Ó¦³³\¦hªº¤u§@
¾÷·|¡C§A¬Ý¨ìÀð¤WÄa±¾µÛ¤@­Óº}«Gªº§i¥ÜµP(note)¡C
LONG
	);
	set("item_desc", (["note":@NOTE

§G§iµP¤W¼gµÛ:
[1;32m
	«Ü°ª¿³¯à¦³¾÷·|¬°±z¤¶²Ð¤u§@¡A½Ð¥ý¬Ý¬Ý¤å¥ó¾ã²z²°(box)
	¤ºªº¤u§@¾÷·|¡A¦pªG³ßÅw½Ð¸òªA°È¤H­ûÁ¿¡A§Ú­Ì±N·|¿Ë¤Áªº
	¬°±zªA°È¡CÁÂÁÂ±zªº¥úÁ{¡C

[1;33m					* Â¾·~¤¶²Ð©Ò *
[m
NOTE
        ,"box":@NOTE

³o­Ó²°¤l¤W¼gµÛ¡u¤u§@¾÷·|¡v¥|­Ó¦r¡A¸Ì­±¸ËµÛ¤@Å|¤@Å|ªº¤å¥ó¡C

NOTE
	]) );

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room064",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/woman" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}