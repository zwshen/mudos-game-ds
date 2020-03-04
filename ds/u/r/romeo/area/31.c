// Room: /u/k/king/area/31.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
³o¸Ì´N¬O¾Ô°ê¬Ó³®²Ä¤G¼h¡Aªï­±§j¨Óªº´N¬O¤@°}³±­·¡A§A¨­¤WªºÂû¥Ö
ª¸½D³£¥H¸g±¼º¡¦a¤F¡A¨ì¥X³B³£¬O¤M¼C¡A¦n¹³¾Ôª§¤~­èµ²§ô¡A§Aªº¤ß¤¤¤S
¦³¤FÁx©Äªº·Qªk¡AÁÙ¬O§Ö¨«§a¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r32",
  "down" : __DIR__"r30",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
