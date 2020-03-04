// Room: /open/world1/wilfred/sand/room37.c

inherit ROOM;

void create()
{
	set("short", "[33m¤s¹ë[0m");
	set("long", @LONG
¥u¨£¦b«e¤è¤£»·¤@³B²¤¬°°ªÁqªº¨F¦a¤W¡A·f¤F¤@°é¬]Äæ¡Aªù¤f³B
¯¸µÛ´X¦ì¨­¬ï¶À¦âÃ~¥Ö¦ç¡AÀYÀ¹¶À¦â¥Ö´Uªº¦u½Ã¡A¦b«á¤è¬]Äæ¤º¤É°_
¤F¶À¨FÀ°ªººX¸¹¡Ð¡Ð¶Â¶À´³¯¾ªêÀY¡A¦¹¦a¦u½Ã´ËÄY¡A¬Ý¨Ó¨Ã«D¤[¯d¤§
¦a¡C
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/obj19" : 1,
    __DIR__"npc/npc20_0" : 4,
    __DIR__"npc/npc20_1" : 2,
    __DIR__"npc/npc20_2" : 2,

]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room36_3",
]));
	set("current_light", 1);
	set("outdoors", "land");
	set("no_recall", 1);

	setup();
	replace_program(ROOM);
}
