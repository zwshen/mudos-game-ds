// Room: /u/k/king/area/41.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
³o¸Ì´N¬O¥ú©ú«°¤§¥D¡ÐÅª¤d¸gªº½m¥\³õ¤F¡A¬Ý¨ì¥k¤âÃä¦³¤@¹D¤â¦L¡A
¥ª¤âÃäªº¤@Áûº_¾ð¦³¤@¥b¬O³Q¦B«Ê¡A¥t¤@¥b«o³Q¤õ¤Æ¤F¡A¤£ª¾¹D¬O³Q¤°»ò
®£©ÆªºªZ¥\©ÒÀ»¤¤¡A­n¬O¥´¦b¤H¨­¤W¡A¥u¦³¸òÀF¤ý¤U´Ñªº¥÷¤F¡C 
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r40",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bulada" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
