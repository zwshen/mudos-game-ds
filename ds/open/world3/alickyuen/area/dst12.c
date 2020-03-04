// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CRoad¢IEast[2;37;0m");
	set("long", @LONG
¤H¸s¦b³o¸Ì¥ªÀ½¥k´é¡A§A®t¤@ÂI´N³Q­¢¨«¥X¥h¡C­ì¨Ó³o¸Ì¥_­±ªº¨º¶¡
´N¬O¹£¦Wªº³J¿|©±¡A¨C¤Ñ³£¦³¤@¸s¤H¨Ó³o¸Ì¶R¥L­Ìªº³J¿|¡A¦Ó¥B³o¸Ìªºªþ
ªñ¬O¤@­Ó¾÷±ñ°Êª«¶é¡A©Ò¥H³o³J¿|©±ªº«È¤H·U¨Ó·U¦h¡C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dst11.c",
  "north" : __DIR__"cakeshop",
  "east" : __DIR__"dst13.c",
]));
set("objects",([
__DIR__"npc/soser" : 1,
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
