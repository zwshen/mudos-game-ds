// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST¡CRoad¢ISouth[2;37;0m");
	set("long", @LONG
¬Ý¨ì«e­±³o®y¥¨«¬ªº«Ø¿vª«¡A´Nª¾¹D¤£¬O¥¼¨Ó¥@¬É®É«Ø³yªº¡C¤@®y§»
°¶ªº±Ð°ó¡A¬Ý¤W¥h´N¹³¦³¹L¦Ê¦~¾ú¥v¡A¬O¨ü°ê®a«OÅ@ªº¥j¥N«Ø¿v¡C¦ý¬O¡A
§A±q³o¶¡±Ð°ó¤W¡A§¹¥þ·PÄ±¤£¨ì¯«¸t¡AÁÙ¦³¤@ÂI³±´Ë®£©Æ¡D¡D¡D¡D¡D¡D
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dst3.c",
  "south" : __DIR__"dst1.c",
  "west" : __DIR__"church",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
