// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"¯]Ä_©±"NOR);
	set("long", @LONG
§A¦b¤@¶¡¯]Ä_©±¸Ì¡AÂd¤l¸Ì¦³¦n¦hªº¶Q­«Ä_¥Û¤Î¦W¶Q¸Ë¹¢«~¡A«°¸Ìªº
©~¥Á³£·|¦b³o¶R¨ì¥L­Ì©Ò³ß·Rªº¦ÕÀô¡B¶µÁå¡B§Ù«üµ¥µ¥º}«Gªº¹¢«~¡AºØÃþ
Ác¦h¡A¥Ø¤£·vµ¹¡CÀð¤W¦³­Ó§G§iµP(note)¡C
LONG
	);
	set("item_desc", ([
	"note":@NOTE
[1;32m
§G§iµP¤W¼gµÛ:

		buy       ¦V¦ÑÁó¶RªF¦è
		list      ¦ÑÁó·|§i¶D§A³o¸Ì½æ¨Ç¤°»ò
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room012",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss1.c" : 1,
	]));

	set("no_clean_up", 0);
	set("valid_startroom",1);
	set("light", 1);
	set("room_type","sell");	

	setup();
	replace_program(ROOM);
}