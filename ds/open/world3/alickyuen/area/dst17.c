// Room: /open/world3/alickyuen/area/dst17.c

inherit ROOM;

void create()
{
	set("short", "[1;36mCircle tunnel¢ISaint[2;37;0m");
	set("long", @LONG
§A¥¿¨«µÛ¤@±ø³s±µsaint «°©MÄq°Ïªº¦æ¤H³q¹D¡A©¹«nª½¨«¥i³q©¹ÂÂ¥@
¬É±ÄÄq°Ï¡A©¹¥_¤£»·³B´N¬O«°ªù¤F¡AºÉ¬O¾ÖÀ½ªº¤H¼é¡C³o±ø³q¹D§e³B¦b¤@
¶êºÞ§Îªº¨¾Å@Á¡½¦¤¤¡A§¹¥þ¦a¹jÂ÷¤FÄq°Ï¤¤¦¾Â©Ãø»DªºªÅ®ð¡C
LONG
	);
	set("world", "future");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/world3/tmr/basic/district1",
  "enter" : __DIR__"gate1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
