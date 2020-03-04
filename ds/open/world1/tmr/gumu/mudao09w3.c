// Room: /open/world1/tmr/gumu/mudao09w3.c

inherit ROOM;

void create()
{
	set("short", "[1;32m¹Ó¹D[0m");
	set("long", @LONG
³o¨½¬O¥j¹Ó¤¤ªº¹Ó¹D¡A¥|©P±K¤£³z­·¡A­ÉµÛùÙ¤W©ü·tªº¿O¥ú¡A§A¯à
«j±j¤À¿ë¥X¤è¦V¡CùÙ¬O¥Î¾ã¶ôªº«C¥Û¬ä¦X°_¨Óªº¡A±µ¦X±o¬Æ¬O§¹¬ü¡AÃø
¥H±q¤¤§ä¥X¤@µ·Á_»Ø¡C¿O¥ú·Ó¦b«C¥Û¾À¤W¡A°{Ã{µÛºÑ«Õ«Õªº¥úÂI¡C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mudao09w4",
  "east" : __DIR__"mudao09w2",
]));

	setup();
	replace_program(ROOM);
}
