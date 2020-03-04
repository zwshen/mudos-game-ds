// Room: /u/k/king/area/r38.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
¤G¤Q¦~«e¯ÀÁÙ¯u¸òÅ]»í¦b³o¤@¾Ô¡A¯ÀÁÙ¯u¨Ï¥Î¤é¤ë¦P¤Ñ¡A±NÅ]»íÀ»±Ñ
¡A¤]±N³o¸Ìµ¹·´¤F¡A­ì¥»¬üÄRªº¤sªe²{¦bÅÜ¦¨¤@¹M¶À¤g¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r39",
  "north" : __DIR__"r37",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
