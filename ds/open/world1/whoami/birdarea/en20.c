// Room: /open/world1/whoami/birdarea/en20.c

inherit ROOM;

void create()
{
	set("short", "[1;37mªF¥_[0m¿AªL");
	set("long", @LONG
§A²{¦b¨Ó¨ìªF¥_¿AªLªº²`³B¡A³oªþªñ¨S¦³¤°»òªF¦è¡A¥u¦³¨â
®Çªº¾ðÂO¡A©M¸ô¤Wªº´X®Ú¤p¯ó¡A«e¤è¬Ý°_¨Óªh®ð«Ü­«¡A¥i¯à§Ö¨ì
ªh¿A¦a±a¤F¡A³o±ø¸ô¤@ª½©¹ªF¤è©µ¦ù¤U¥h¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"en21",
  "west" : __DIR__"en19",
]));
	set("outdoors", "forest");
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
