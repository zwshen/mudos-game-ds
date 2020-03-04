// Room: /u/b/bennyng/area/room23.c

inherit ROOM;

void create()
{
	set("short", "寶瓶宮");
	set("long", @LONG
這裡白光一片，四周不見景物，到處透出寒氣，使你身體不停的發震
，開始有傷風的感覺．你真想找些保暖的衣物穿穿，然而這是不可能的事
因為四周死寂一片，找不出任何事物．
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room22",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
