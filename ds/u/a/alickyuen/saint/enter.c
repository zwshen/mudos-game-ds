// Room: /u/a/alickyuen/area/enter.c

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CDoor¢ICyberZoo[2;37;0m");
	set("long", @LONG
³o¸Ì¬OSaint¸Ì³Ì¦³¦Wªº¾÷±ñ°Êª«¶é¡A³o¸Ìªº°Êª«³£¬O¥ÑSaintªº¬ì¾Ç
®a¬ã¨s¥X¨Óªº¡A¦ý¬O¥L­Ì³£¥i¥H¥Í¨|ªº¡C¦]¬°©Ò¦³ªº°Êª«³£®t¤£¦hµ´ºØ¤F
¡A©Ò¥H¥¼¨Ó¥@¬ÉªºÃdª«³£¬O¾÷±ñ¤Æªº¡C§A¥i¥H¨ì¤J³õ³B¶R²¼¤J¥h¬Ý°Êª«¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"door.c",
  "enter" : __DIR__"enter2.c",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
