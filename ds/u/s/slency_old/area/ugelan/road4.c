// Room: /u/s/slency/area/ugelan/road4.c

inherit ROOM;

void create()
{
	set("short", "[1;33m«Õ¾BÄõ¤j¹D[2;37;0m");
	set("long", @LONG
¤@±ø¥Ñ«C¥Û©Ò¾Q¦¨ªº¼eÁï¹D¸ô¡A¨«¨ì¦¹³B¡A¸ô¬ðµMÅÜ¼e´¯°_¨Ó¡A¨Ó
©¹ªº¤H­Ì¤]§ó¦h¤F¡A»·³B§A¥i¥HÁô¬ù¬Ý¨£¤@®y§»°¶ªº¦Q¾ô¾î¸ó¦bÅ@«°ªe
ªº¨â©¤¡A¾ã­Ó®ð¶H¤Q¤À§§Æ[¡AªF¦è¦V¬O¤@±ø¼e¼sªº¤H¦æ¤j¹D¡C
LONG
	);
	set("outdoors", "land");	
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road15",
  "west" : __DIR__"road6",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
