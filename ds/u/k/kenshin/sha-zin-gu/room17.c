// Room: /u/k/kenshin/sha-zin-gu/room17.c

inherit ROOM;

void create()
{
	set("short", "[33m¤EÀs«È´Ì[0m");
	set("long", @LONG
·v¤é¨¦¸Ì°ß¤@ªº«È´Ì¡A¤@¶i¥h´N»D¨ì¥Î¹D¦a¶À¤s¤gÂû©Ò²i½Õªº
¶À¤sÂû»L¡AÅ¥»¡Âí¤WÁÙ¦³¥H¦Ê¬r¤§¤ý¸¼°G©Ò½Õ¦¨ªº¸¼°G°s¡A¦ý¬O³Ì
¥D­nªºÁÙ¬O¥»«È´Ì©±¤p¤Gªº¿Ë¤Á©Û©I¡AÅý¤HÄ±±o¦b³o¸Ì¶RªF¦è¬O²z
©Ò·íµMªº¡C
LONG
	);
	set("room_type", "hotel");
	set("no_fight", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/npc/waiter" : 1,
]));
	set("current_light", 3);
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room18",
  "east" : __DIR__"room16",
]));
	set("valid_startroom", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
