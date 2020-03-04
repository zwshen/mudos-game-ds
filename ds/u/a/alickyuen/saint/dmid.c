// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CCenter¢IMiddle[2;37;0m");
	set("long", @LONG
³o¸Ì´N¬OSaintªºCentre¤F¡A³£¬O¦bSaintªº¥¿¤¤¥¡¦ì¸m¡C§A¥i¥H±N³o
¸Ì·í°µ§A¦b³o«°¥«³}ªº¥XµoÂI¡A¦]¬°³o¸Ì¤H¦h©ö»{¡A¤£©È·|°g¸ô¡C³o¸Ì¦³
ªF¡B«n¡B¦è¡B¥_¥|­Ó¤è¦V¡A§A¦Û¤v¨ì³B³}³}¡A»¡¤£©w¦³·N¥~¦¬Ã¬¡C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"dst3.c",
  "west" : __DIR__"dst7.c",
  "north" : __DIR__"dst5.c",
  "east" : __DIR__"dst6.c",
]));
   set("outdoors","land");
	set("world", "future");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/pot.c" : 1,
__DIR__"npc/child.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
