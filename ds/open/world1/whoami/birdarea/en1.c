// Room: /open/world1/whoami/birdarea/en1.c

inherit ROOM;

void create()
{
	set("short", "[1;37mªF¥_[0m¿AªL");
	set("long", @LONG
§A¨Ó¨ì¤FªF¥_¿AªLªº¤J¤f³B¡AªF¥_¿AªLªº®ð­Ô¤Q¤ÀÀê¼ö¤S¼é
Àã¡A¸}¤UªºªdÀ×½ò°_¨ÓÃPÃP³n³nªº¡A¥|©Pªº¾ð¤ìªøªº»á¬°°ª¤j¡A
»\¦í¤F¤j³¡¥÷ªº¶§¥ú¡C©¹ªF¥_¦V¦³­Ó¤p¸ô¥i¥H§ó²`ªF¥_¿AªL¸Ì¡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"en2",
]));
	set("outdoors", "forest");
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
