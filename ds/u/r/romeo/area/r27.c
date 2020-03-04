// Room: /u/k/king/area/r27.c

inherit ROOM;

void create()
{
	set("short", "[1;35m°­«°[1;37m-[1;34m¤­¤æ°g¬P°}[2;37;0m");
	set("long", @LONG
³o¸Ì¬O³q©¹°­¤ý·µªº²Ä¤@¼h¾÷Ãö¡A³oÃäªº°}¦¡¬O¥Ñ¤­§ÎÅÜ¤Æ
¦Ó¨Óªº¡A¥Rº¡¤F¥È§®¡A¸ò¤@¯ëªº°}ªk§¹¥þ¤£¦P¡A·Q­n³q¹L³o¸Ì¨Ã
¤£¬O¦p¦¹®e©ö¡C¬Ý¬Ý¥|©P¤]³£¥u¦³¤@°ï°ïªº¯î¥Û¡A¨«µÛ¨«µÛ³£¤@
ª½¦^¨ì­ì¦a¡Aµ¥§A¨«¨ìºë¯h¤OºÉªº®É­Ô¡A±N·|¦³¤@¸s©ÇÃ~¨Ó¼¹µõ
§A¡Aª½¨ì§A¦º¤`¡C
LONG
	);
	set("no_recall", 1);
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chen" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r23",
  "west" : __DIR__"r23",
  "north" : __DIR__"r28",
  "east" : __DIR__"r26",
]));
	set("no_clean_up", 0);
	set("no_steal", 1);

	setup();
	replace_program(ROOM);
}
