// Room: /open/world1/whoami/birdarea/village2.c

inherit ROOM;

void create()
{
	set("short", "[1;37mªF¥_[0m¿AªL");
	set("long", @LONG
§AªuµÛªd¤g¸ô¨«¨ì¤F³o¸Ì¡A¹D¸ô¨â®Ç¬O¨â±Æ­Z±Kªº¾ðªL¡Aªþªñ
¦³¤@¨Ç©_©Çªºªá¯ó¡AÄ~Äò©¹ªFÃä¨«¥i¥H³q¨ìÂyª°§ø¡A±q³o¨à¥i¥H±æ
¨£ªFÃä¦³­Ó¥¨¤jµL¤ñªº¥Û«ýªù¡AÁÙ¦³´X­Ó¬ïµÛ©_¸Ë²§ªAªº¤H¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"village3",
  "west" : __DIR__"village1",
]));
	set("outdoors", "forest");
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
