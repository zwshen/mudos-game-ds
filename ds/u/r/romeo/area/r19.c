// Room: /u/k/king/area/r19.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[1;37m-[1;35m°­«°[2;37;0m");
	set("long", @LONG
¨«¤F¤@¬q¬Û·íªøªº¸ô¡A¬ï´¡©ó§L°¨«M¤§¶¡¡A¶g³òÄjº©µÛ¤@ªÑ¦º®ð¡A
¹ê¦b¤£¬O°®²b¤§¦a¡A³o¸Ì¶Z¬Ó³®®c¤v¦³¤@¨½ªº¥ú´º¡A±q³o¸Ì©¹¥|¶g¬Ý¥h
¡A¥u¨£«á¤è¦³µÛ§ó¼e¼sªº¦a¤è¡A·¥¥Ø±æ¥h¡A¦b»·¤èÁô¬ù¥i¥H¨£¨ì¤@®y®y
ªº¥¨¤jÀJ¹³¡AµÛ¹ê¥iºÃ¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r20",
  "northwest" : __DIR__"r18",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man" : 3,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
