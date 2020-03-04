// Room: /open/world1/whoami/birdarea/en76.c

inherit ROOM;

void create()
{
	set("short", "[1;37mªF¥_[0m¿AªL");
	set("long", @LONG
§A©¹¥_¨«¤F¹L¨Ó¡Aªþªñªº¾ð¤ìÁÙ¬O¤@¼Ëªº­Z±K¡A¦ý¬O§A©¹§ó
»·ªº¦a¤è±æ¥h¡A«o³Q¤s¸sªº®k¾À©ÒÀôÂ¶¡A³o±ø¤p¸ô©¹ªF¤è©µ¦ù¥X
¥h¡A¥i¥H¬Ý¨ì¤@³B°ª°ªªº¥Û¥x¡A©¹¥_¬Oªþªñ°ß¤@ªº§ø²ø-¥_ÆZ§ø¡A
¥_ÆZ§øªº¤j¦h¼Æ§ø¥Á¡A³£«D±`¦n«È¡A§A¥i¥H¦Ò¼{¹L¥h·²­Ó¸}¡C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"en75",
  "north" : "/open/world1/tmr/north_bar/town1",
  "east" : __DIR__"en78",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
