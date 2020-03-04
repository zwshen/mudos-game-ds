// Room: /u/k/king/area/r21.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[1;37m-[1;35m°­«°[2;37;0m");
	set("long", @LONG
³o¸Ì´N¬O¾Ô°ê¬Ó³®²Ä¤@¼h¤F¡A§A¥i¥H¨ì³o¸Ì¨Ó¤w¸g¥Nªí§AªºªZ¥\­×¬°¤w
¸g¦³¤@©wªºµ{«×¤F¡A¦A¤U¥h§A¤]¥u¦³¦º¸ô¤@±ø¡A¥|©P¤]³£¥u¦³¤@°ï°ïªº¾uÅ\
ÀY¡A¤£ª¾¹D¦h¤Ö¥j¥Nªº°ª¤â¦º¦b³o¸Ì¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r22",
  "down" : __DIR__"r20",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
