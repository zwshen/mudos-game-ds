// Room: /u/k/kenshin/sha-zin-gu/room23.c

inherit ROOM;

void create()
{
	set("short", "[1;33m¤j¶¯Ä_·µ[0m");
	set("long", @LONG
³o´N¬O¹p­µ¦xªº°µ¦­¡B±ß½Òªº¥²³Æ³õ©Ò¢w¤j¶¯Ä_·µ¤F¡A¨ì¤F³o¬Ý
¨ì¶¯°¶ªº¦ò¹³¡A¤£¸TÅý¤H¤]±o«ô­Ó¥L¨â¤T¤U¡C
LONG
	);
	set("light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room22",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
