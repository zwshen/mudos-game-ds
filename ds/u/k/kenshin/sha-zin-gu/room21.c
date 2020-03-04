// Room: /u/k/kenshin/sha-zin-gu/room21.c

inherit ROOM;

void create()
{
	set("short", "[1;33m¹p­µ¦x[0m¦x¤f[0m");
	set("long", @LONG
²×©ó¨Ó¨ì¹p­µ¦x¤F¡A¬Ý¨ì¨º²øÄYªº¦x¼q¡A¤ß¸Ì¤]¤£¸TªºÄYÂÔ¨Ç¡A¥­
±`¦³ªº¯º®e¤]¦¬°_¤F¤£¤Ö¡C°£¤F¬Ý¨ì´Â«ôªº¤H¥Á¡A¤]¬Ý¨ì¦x¸Ìªºªº¼q¤½
¦bÀ°¤@¨Ç·í¦aªº©~¥Á¸ÑÅÒ°g¡A¤ß¸Ì·Q¤@·Q¡A³o¨Ç¤H¥Á¯u¬O°g«H¡A¤£¹L«e
¤H©Ò¥Ü¹ç¥i«H¨ä¦³¡B¤£¥i«H¨äµL¡AÀ³¸Ó´N¬O³o­Ó·N«ä§a¡C
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"room20",
  "north" : __DIR__"room22",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
