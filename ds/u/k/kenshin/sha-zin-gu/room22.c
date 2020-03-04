// Room: /u/k/kenshin/sha-zin-gu/room22.c

inherit ROOM;

void create()
{
	set("short", "[1;33m¹p­µ¦x¤º[0m");
	set("long", @LONG
¨Ó¨ì¤F¦x¤º¡A¬Ý¨ì³\¦h¤H°Ñ«ô¦p¦¹¶Ç¯«¡A¯u¬OÅý¤H·q¨Ø¤T¤À¡AÁÙ¦³
¦x¤ºªºÂ\³]¤]¬O¤«µM¦³§Ç¡Aªá¯ó¥Íªø¦p¦¹¥Í®ð¯sµM¡C
LONG
	);
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room23",
  "south" : __DIR__"room21",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
