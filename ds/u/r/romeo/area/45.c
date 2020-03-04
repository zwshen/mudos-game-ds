// Room: /u/k/king/area/45.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
³o¸Ì¬O·í¦~¤MÅ]¡Ð¬P³¥´Ý¬õ¦b¦òÅ]¬Ûª§¡A«o¥H¤@¼Ä¥|¤£©¯¸¨±Ñ¡AµªÀ³
°hÁôªº´ò©³¥j¹Ó¡A¥|©P¥u¦³¤@°ï°ïªº¤ô¯ó¡AµM«á«o¤@ÂI¬¡®ð¤]¨S¦³¡A¬Ó³®
ªº°­¨ò¤]³£¤£´±¨Ó«I¥Ç¡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"44",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/blademan" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
