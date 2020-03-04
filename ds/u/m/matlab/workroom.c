// Room: /u/m/matlab/workroom.c

inherit ROOM;

void create()
{
	set("short", "[1;36m¤Ñ¯ó¼C¿c[2;37;0m");
	set("long", @LONG
³o¬O¤Ñ¯ó¥|­¦½m¼C¨H«äªº¦a¤è¡A¤@¤Á¬O¦p¦¹¦a¹çÀR¦w¸Ô¡A±u«â¦b³o¼Ëªºª^³òùØ
§A·PÄ±¨ì¤­©xªº·P¨ü¼Æ¥H­¿­p¦aÆF±Ó°_¨Ó¡A¥|©PªºÂ\³]¤Q¤À¦aÂ²³æ¾ë¯À¡A¥u¬OÀð¤W
©Î²`©Î²Lªº¼C²ª«o¨Ï§A¤j¬°¾_Äà¡A¼C²ªÁôÁô³zµÛµµ«C¦âªº¼C®ð¤[¤[¤£´²¡AÅý§A¹y¥Í
§Ù·V±R·q¤§¤ß¡C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/1.c" : 1,
]));
	set("no_magic", 1);
	set("no_fingt", 0);
	set("connect", "/open/world1/tmr/area/hotel.c");
	set("exits", ([ /* sizeof() == 3 */
  "meet" : "/d/wiz/entrance",
  "pass" : "/open/world1/tmr/area/hotel.c",
  "area" : __DIR__"area/entrance.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
