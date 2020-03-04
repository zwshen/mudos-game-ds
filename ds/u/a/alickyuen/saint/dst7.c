// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CRoad¢IWest[2;37;0m");
	set("long", @LONG
§A©ïÀY±æ¤W¤Ñ¤W¡A¬Ý¨ì«Ü¦h¨®¦bÁa¾î¥æ¿ùªº¨®¹D¤W¾p¹L¡A´Nª¾¹D¥L­Ì
«Ü»°®É¶¡¤F¡C¦Ó§A¦Û¤v´N¦b³o¸Ì¶¢³}µÛ¡A§A¥Î¦Û¤vÆF±Óªº¶åÄ±»D¤F¤@»D¡A
»D¨ì¤@°}«Ü·L®zªº­»¨ý¡A¬Ý¨Ó¬O¥Ñ«Ü»·¶Ç¨Óªº¡A§A¶}©l¦VµÛ³o¥Ø¼Ð¶iµo¡C
LONG
	);
	set("world", "future");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dst14.c",
  "east" : __DIR__"dmid.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
