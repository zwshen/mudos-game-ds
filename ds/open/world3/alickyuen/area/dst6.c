// Room: /u/a/alickyuen/area/dst6.c

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CRoad¢IEast[2;37;0m");
	set("long", @LONG
³o¸Ì±µªñ¥«¤¤¤ß¡A©Ò¥H§A·P¨ì«Ü¹Ë§n¡C¦ý¬O§A¬Ý¨ì«e­±¦³¤@­Ó©_©Çªº²{
¶H¡A´N¬O«e­±»E¶°¤F¤@°ï¤H¸s¡A§Aªº¦n©_¤ß±Ð§A·Q¨ì¨º¸Ì¬Ý¬Ý¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dmid.c",
  "east" : __DIR__"dst11.c",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
