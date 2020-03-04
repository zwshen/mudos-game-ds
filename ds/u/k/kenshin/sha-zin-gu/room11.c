// Room: /u/k/kenshin/sha-zin-gu/room11.c

inherit ROOM;

void create()
{
	set("short", "[1;36mªZ¾Ç¤§¸ô[0m");
	set("long", @LONG
³o¬OÂQ©¹®±¥´¸}½ðªº¤H¥Áªº¥²¸g¤§¸ô¡A¥u­n¦A©¹«e¨«¡A´N¯à¤@¹Á
ªZªÌ±JÄ@¡C©¹¦è¨«¯à¨ì¹F·v¤é¨¦ªº¹A³õ¢w¡yÀÆ¥ú¹A³õ¡z¡C
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room8",
  "north" : __DIR__"room24",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
