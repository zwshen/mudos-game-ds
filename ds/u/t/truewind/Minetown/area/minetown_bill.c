// Room: /u/t/truewind/Minetown/area/minetown_bill.c

inherit ROOM;

void create()
{
	set("short", "[1;34mºÆ¨g¤ñº¸[0m°s§a");
	set("long", @LONG
§A±À¶}°s§aªº¨â®°¬¡°Êªù½ñ¤J¤F°s§a¡A©±¤ºªº¤H¸s¬Ý¨£§A¡A°_¤F
¤@°}¤p¤pªº³Ù¼MÁn¡C³o¸Ìªº³]³ÆÂ²­®¡A¥u¦³§a¥x¸ò´X±iÀ\®à¡A²Ê¾|ªº
Äq¤u­Ì¥¿¤j¤f¦Y¶º¤j¤f³Ü°s¡A§Ë±oªF¤@Åy¦è¤@Åyªº¤ôº{¡AÁÙ¦³¨Ç°s¶q
®tªºÄq¤u³Ü¾K·w­Ë¦b¦a¤W¤£¿ô¤H¨Æ¡C
LONG
	);
	set("objects", ([ 
        __DIR__"npc/bill.c" :1 ,
]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"minetown3",
  "east" : __DIR__"bill_kitchen",
  "up" : __DIR__"minetown_bill1",
]));

	setup();
}
