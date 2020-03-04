// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CRoad¢IEast[2;37;0m");
	set("long", @LONG
¨«¥X¤F¨ºÀ½­¢ªº¤H¸s¡A¶]¨ì¨Ó¾÷±ñ°Êª«¶éªþªñ¡C³o­Ó¾÷±ñ°Êª«¶é¬O³Ì
·s¶}ªº¡A³o¥ç¬O¥@¬É²Ä¤@­Ó¯à°÷Ác´Þ¾÷±ñÃdª«ªº°Êª«¶é¡A¥iºâ¬O¤@­Ó¤j«¬
ªº­p¹º¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dst12.c",
  "east" : __DIR__"door",
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
