// Room: /open/world1/wilfred/meadow/room33.c

inherit ROOM;

void create()
{
	set("short", "[33m¤û¥Ö»X¥j¥][0m");
	set("long", @LONG
³o¸Ì¬O¤@¶¡¤p¤pªº»X¥j¥]¡A¥|¶g§G¸mªº¤Q¤ÀÂ²¼ä¡A¦b¤@®Çªº¨¤¸¨
©ñµÛ¼Æ°¦¤£¦PÃC¦âªº¤û¨¤¹¢ª«¡A¦ü¥G¬O±q¬º¤û¨­¤W¨ú¤U¨Óªº¨¤¡A¤j¤p
¤£¤@¡A¨ä¤¤³Ì¤jªº¬ù¨k¤l¤p»L¯ë²Êªø¡C¥t¥~°£¤F¤@¨Ç¤é±`¥Í¬¡¥Î«~¤§
¥~¡A¦A¤]µL¨ä¥L¤Þ¤Hª`¥Ø¤§ª«¡C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/npc2" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room21",
  "north" : __DIR__"room36",
]));

	setup();
	replace_program(ROOM);
}
