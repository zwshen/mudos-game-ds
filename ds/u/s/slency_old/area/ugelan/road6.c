// Room: /u/s/slency/area/ugelan/road6.c

inherit ROOM;

void create()
{
	set("short", "[1;33m«Õ¾BÄõ¤j¹D[2;37;0m");
	set("long", @LONG
³o¸Ì¬O«Õ¾BÄõ«°µÛ¦Wªº«Õ¾BÄõ«°¤j¹D¡A¦¹¤Wªº­·¥ú»P¤H¸sÅ¨¦«¥X«Õ
¾BÄõ«Ò°êªº°¶¤j»P´I±f¡A±q¨C­Ó¦æ¤H®T®®ªºªí±¡¡A§A¥i¥H·P¨ü¨ì»´ÃP»P
µÎªAªº·PÄ±¡AÅ@«°ªeªºªe­±¤Ï¬MµÛ¬Ó®cªº­Ë¼v¡A¦h¬üªº¤@®y«°°Ú!!
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road5",
  "east" : __DIR__"road4",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
