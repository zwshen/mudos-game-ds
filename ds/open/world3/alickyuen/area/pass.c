//updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CBuilding¢IEnterance[2;37;0m");
	set("long", @LONG
³o¸Ì¬O¤@­Ó³q¦æÃÒªº¥Ó½Ð¯¸¡A¨ì³o¸Ì¥i¥H¬°¤@¨Ç¦³»Ý­nªº¤H¤h§Ö±¶¥Ó
½Ð¨ì³q¦æÃÒÂ÷¶}³o­Ó°ê®a¡C¦ý·í§A·Q¥Ó½Ð§ó°ª¯Åªº³q¦æÃÒ¥h¨ä¥L¬P²y®É¡A
§A´N»Ý­n¨ì¦t©z¤H¥Á¤J¹Ò¨Æ°È³B¸Ì¿ì²z¤âÄò¡A¦]¬°³o¸Ì¤£´£¨Ñªº¡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dst14",
]));
set("objects", ([
__DIR__"npc/passport.c" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
