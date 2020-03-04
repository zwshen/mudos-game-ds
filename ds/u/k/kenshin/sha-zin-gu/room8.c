// Room: /u/k/kenshin/sha-zin-gu/room8.c

inherit ROOM;

void create()
{
	set("short", "[1;32m¤¤¥¡¼s³õ[0m");
	set("long", @LONG
¨«¨ì¤¤¥¡¼s³õ«á¡A³o´N¬O·v¤é¨¦ªº©~¥Á¤é±`ªº¬y°Ê©Ò¦b³B¡A·PÄ±
¨ì©~¥Áªº¼ö±¡¡AÅý¤HÄ±±o¤£ªP¨Ó¨ì¦¹¦a¡C©¹ªF±æ¯à¬Ý¨ì³\¦h©±®a¦pªG
­n¨D¯««ô¦ò¡A¥i©¹¦èÃä¨«¥h¡Cµ§ª½¦V«eªº¸Ü¡A¯à¬Ý¨ì«eªZªL¤Ö«L¹çªö
©M¦bÂí¤ºªºªZ¾Ç°^Äm¡AÅ¥·í¦a©~¥Á©Ò¥Ü¡A¦b¤£¤[¤§«e¹çªö©M¦b·í¦aÅP
¶}¤F¤@¶¡ªº¹DÀ]¡A¦W¬°¡yªZ¾Ç¤§®a¡z¡A¤£±¤¥N»ù±Ð¾É·í¦a·Q²ßªZ¾Ç¤§
¤H¡A³oºØµ½¤ß¡A¤Ñ¤U¶¡¯u¬OÃø§ä°Ú¡I
LONG
	);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room10",
  "east" : __DIR__"room9",
  "north" : __DIR__"room11",
  "south" : __DIR__"room7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
