// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CRoad¢IWest[2;37;0m");
	set("long", @LONG
¦b«n­±ªº¤@­Ó¦a¤è¡A§A¥i¥H¦b¨º¸Ì¥Ó½Ð¤@¥»Á{®É³q¦æÃÒ¡A§@¬°¤£®É¤§
»Ý¡C¦Ó§A¥çµo²{¤F­»¨ý¤Sªñ¤F¤@ÂI¡A¬Ý¨Ó¨«³o­Ó¤è¦V·Ç¨S¿ùªº¡C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"pass",
  "west" : __DIR__"dst15.c",
  "east" : __DIR__"dst7.c",
]));
set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
