// Room: /open/world1/tmr/gumu/mudao09w8.c

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
	set("current_light", 4);
	set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"mudao10",
    "southeast" : __DIR__"mudao09w7.c",
]));
        set("objects", ([ /* sizeof() == 1*/
          __DIR__"npc/apprentice" : 3,
        ]));      


	setup();
	replace_program(ROOM);
}
