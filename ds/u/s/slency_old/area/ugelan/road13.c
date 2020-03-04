// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "[1;33m«Õ¾BÄõ¤j¹D[2;37;0m");
	set("long",@LONG
³o¸Ì¬O¤@±ø¾î³e¦¹«°ªF¦èªºª÷¦â¤j¹D¡A¦¹¦aªºÁcºa¹ê¤£¦b¸Ü¤U¡A°ª
¶Qºë½oªº©ÐªÙ³]­p»P»¨µØ°¨¨®ªº¨Ó©¹¬ï±ô¡A³B³BÂI©ú¤F«Õ¾BÄõ«Ò°ê¤£±Ñ
°ò·~ªº¨Æ¹ê¡A¸ô®Ç¦³¤@¨Ç¨Ñ¸ô¤H·²¸}ªº®y´È¡A§¤¦b¨º¨à§j§j²M­··Q¨Ó¬O
¥O¤H¶o¾Kªº¨É¨ü¡C
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road12",
  "east" : __DIR__"road5",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
