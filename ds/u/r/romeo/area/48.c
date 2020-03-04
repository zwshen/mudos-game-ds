// Room: /u/k/king/area/48.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m°­¤ý·µ");
	set("long", @LONG
³o¸Ì´N¬O°­¤ý·µªº¤jªù¤f¤F¡A¨«¨ìªù¤f¤@ªÑµL§Îªº¤O¶q´N§â§Aµw¥Í¥Í
ªº±À¤F¥X¨Ó¡A¥|©Pªº³±®ð¤S¤ñ¤§«e§ó¥[ªº¾®­«¡A¬Ý¨Ó¬O¤£¯à¨«¦^ÀY¸ô¤F¡A
¥u¦³µw«÷¬Ý¬Ý¤~¦³¤@±ø¥Í¸ô¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"49",
  "south" : __DIR__"47",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
