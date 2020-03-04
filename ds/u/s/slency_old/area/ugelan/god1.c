// Room: /u/s/slency/area/ugelan/god1.c
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m¡i[2;37;0m¦Ð¸t¶®±Ð°ó¤jªù[1;37m¡j[2;37;0m");
	set("long", @LONG
³o¸Ì¬O¦Ð¸t¶®±Ð°óªº¤jªù¤f¡A±qÀð¤Wºë²ÓªºÀJ¨è¡A¸¨¦aµ¡¤WÂAÆAªº
±m¦â¬Á¼þ¸Ë¹¢¡A«K¥i·Q¨£¤º³¡ªº¸ËæC¥²¬O¬Û·í²øÄY¯«¸tªº¡A·L·L¦a§A¥i
¥HÅ¥¨£¯«¼Öªº±Û«ß¦bªÅ¤¤·n¦²¡A¤j¦a¦b®Ç³­Å¨µÛ³o´É¥ÛÀY«Ø¿v¡A¤@¤Á³£
¬O¦p¦¹ªº²øÄYµÂ¿p¡A©¹¦è¨«¥i¥H¦^¨ì«°¤¤¡C
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "¤jªù" : "ÀJ¨è¤Q¤Àºë½oªº¤@®°¤jªù¡C
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"church4",
  "east" : __DIR__"god2",
]));
	create_door("east", "¤jªù", "west", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
