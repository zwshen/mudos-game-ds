// Room: /u/k/kenshin/sha-zin-gu/room18.c

inherit ROOM;

void create()
{
	set("short", "[33m¤EÀs«È´Ì¤G¼Ó[0m");
	set("long", @LONG
³o¸Ì¬OÅý¤H²á¤Ñ½Í¤ßªº©Ò¦b¡A§A¥i¥H±a§Aªº¦n¤Í©Î¾Ô¤Í¨Ó¨ì³o¡A
©}½¥ªø½Í¡A©ÎªÌ¥i§Q¥Î®ÇÃä¦³ªº¶H´Ñ¡A¨M¾Ô¤@µf¡A¥iÅý§A»P¥L¤HªºÃö
«Y§ó¦n§ó°í©w¡C
LONG
	);
	set("no_goto_cmd", 1);
	set("room_type", "hotel");
	set("no_steal", 1);
	set("no_fight", 1);
	set("no_exert", 1);
	set("no_kill", 1);
	set("current_light", 3);
	set("light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"room17",
]));
	set("valid_startroom", 1);
	set("no_cast", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
