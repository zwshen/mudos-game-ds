// Room: /u/l/lestia/area/sn14.c

inherit ROOM;

void create()
{
	set("short", "よ此狶-畖");
	set("long", @LONG
禫┕此狶ず场ǐ碞禫綼艶ほ﹙┮瘤礛硂⊿Τぐ或此
腨称俱畒此狶硓臩ぃ玙デ﹍沧稱ぃ硓
ぐ或ρ肚–秈此狶ず矪羆⊿Τㄓ
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"sn15",
  "north" : __DIR__"sn13",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
