// Room: /u/s/shengsan/workroom.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "[1;36mÂÅÂÅªº¤Ñ¥ð¾Í®x°|[0m");
	set("long", @LONG
³o¸Ì¬OÂÅÂÅªº¤Ñ¥ð¾Í®x°|¡A¨S¦³¤Ó¦hªºÂZÄc¡A¤]¨S¦³¤Ó¦h·Ð
¤Hªº¤½¨Æ¡C¤@¤ÁµL¼~»PµL¼{³£¥i¥H¦b³o¬üÄRªº®x°|¤¤§ä¨ì¡A¼ë¼ë
ªº¬y¤ôÁn¡A®S®Sªº³¾³ÚÁn¡AÅ¥±oÅý§A¤ßÄq¯«©É¡A©{¦p¦Û¤v¤w¸g¨ì
¤F¤H¶¡ªº²b¤g®çªá¶é¤§¤¤¤F¡C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		"/u/s/shengsan/npc/beauty" : 1,
		"/u/s/shengsan/npc/handsome" : 1,
	]));


	set("exits", ([ /* sizeof() == 7 */
		"wiz": "/d/wiz/hall1",
		"west" : SHENGSAN1+"testarea/landroom",
		"play":	SHENGSAN2"game/playroom",
		"east": __DIR__"mine/room01",
		"marry": SHENGSAN2+"marryhome/househ1"
            ]));

	set("light", 1);
	set("valid_startroom",1);
	set("no_clean_up", 0);
	setup();
        call_other("/obj/board/shengsan_b.c", "???");
	replace_program(ROOM);
}
