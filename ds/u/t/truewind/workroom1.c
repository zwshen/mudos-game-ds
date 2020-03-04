// Room: /u/t/truewind/workroom1.c

inherit ROOM;

void create()
{
	set("short", "[1;37m«ä¹L±V[0m");
	set("long", @LONG
¦¹³B¬OÂ_±V«n¤èªº¤@¶ôªÅ¦a¡AÄ²¥Ø©Ò¤ÎºÉ¬O¥Õ½J½Jªº´º¶H¡A©P³ò
³Q¤s¾ÀÀô©ê¡A°¸¦Ó·|¦³³¥¥Í°Êª«¸g¹L¡C¦b»dãé¯U¯¶ªº¤p¹D¤W¨Ìµ}¥i¥H
¬Ý¨ì¤@¨Ç¤j¤j¤p¤pªº¸}¦L©MÂ_¸¨ªºªQ¾ðªK¡C
LONG
	);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"workroom",
  "south" : "/u/t/truewind/Minetown/area/minetown",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
