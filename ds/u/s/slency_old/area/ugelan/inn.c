// Room: /u/s/slency/area/ugelan/inn.c

inherit ROOM;

void create()
{
	set("short", "[1;37m«ÕÄõ®È©±[2;37;0m");
	set("long", @LONG
³o¸Ì¬O¥»«°³Ì¤jªº¤@¶¡®È©±¡A³o¸Ìªº¤H¼é¨Ó©¹º³Äc¡A¤Q¤À¼ö¾x¡A¤£
®É¥i¥HÅ¥¨ì¤@¨Ç¥¿¦b¥Î¶ºªº®È«È­Ì¡A¤j½ÍÁï½×¥L­Ì®È³~¤¤©Òµo¥Íªº©_»D
²§¨Æ¡A³o¸Ì¨ÑÀ³­¹ª«¤Î¥Í¬¡¥Î«~¡A»Ý­n¤°»òªº¸Ü¦VªA°È¥Í¸ß°Ý¡A¥L·|«Ü
¼Ö·N´À§A¸Ñ¨M¥Í¬¡ªº°ÝÃD¡C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"innroom1",
  "south" : __DIR__"road1",
  "north" : __DIR__"road18",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/waiter" : 1,
  __DIR__"npc/obj/mapwood" : 1,
]));
        set("no_fight", 1);
	set("valid_startroom",1); 
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
