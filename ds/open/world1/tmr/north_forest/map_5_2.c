// Room: /u/l/lestia/area/map_5_2.c

inherit ROOM;

void create()
{
	set("short", "靈幻宗祭壇-廂房走道");
	set("long", @LONG
一條用檜木所建造的走道在你腳下被你踩的咚咚作響，彷彿在抗議著你
前進的腳步太沉重，吵到在廂房休息的貴賓們，後方通往靈幻教的大殿後廳
，東邊則是通往貴賓休息的廂房。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"map_5_3",
  "south" : __DIR__"map_6_2",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
