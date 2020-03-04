// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CRoad¢ISouth[2;37;0m");
	set("long", @LONG
¤@±ø³sµ²Centre©MShipªºµó¹D¡A¥­±`ªº¤H¸g¹L³o±øµó¹D¡A³£¤£·|¯d·N
¨ì³o±øµó¹Dªº¯S¦â¦ó¦b¡C¦ý·í§A¦b³o¸Ì¯d¤ß¤@¬Ý¡A´N·|µo²{¨ì¤@¨Ç¥­®É§A
ª`·N¤£¨ì¦Ó¤S¥O§AÅå³Yªº¨Æ¡D¡D¡D¡D¡D¡D
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dst2.c",
  "north" : __DIR__"dmid.c",
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
