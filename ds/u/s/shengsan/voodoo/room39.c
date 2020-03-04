
inherit ROOM;

void create()
{
	set("short", "[1;36m§Å¬r±Ð±Ð¾Â[m");
	set("long", @LONG
§A¬Ý¨ì¤F²øÄYªºÂ\³]¤ÎµÂ¿pªº¸Ë¹¢«~¦b±Ð¾Â¸Ì¿ô¥Øªº¦a¤è¡C³o¸Ì¬O±Ð
®{­Ì½¤«ô¯«ÆFªº¦a¤è¡A¨C¨ì­«­nªº¸`¤é¡A±Ð®{­Ì³£·|¦b³o¶}·|¤Î¶}³]ªk¾Â
¡A§Å¬r±Ðªº±Ð¥D¤]·|¥D«ù²½¨å¹ï±Ð®{«Å´­±Ð«Â¡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room38",
            ]));

	set("objects", ([ /* sizeof() == 2 */
            __DIR__"mob/leader" : 1,
	    __DIR__"mob/protector" : 2,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
