// Room: /u/t/tmr/area/ms3.c

inherit ROOM;

void create()
{
	set("short", "小池塘");
	set("long", @LONG
你正站在小池塘前，池畔有棵數人合抱的大榕樹，樹葉茂盛繁多，樹
底下正趴著一隻懶洋洋的大牯牛，池塘裡的荷花也迎著陽光正自盈盈綻放
，荷葉上的田蛙也嘓嘓作聲，渾然結成一片安詳的小天地。
LONG
	);
	set("item_desc", ([ /* sizeof() == 2 */
  "荷花" : "靜立於池面上的荷花，散發出芬芳的香味，令人愛不釋手。
",
  "大牯牛" : "一隻正在樹蔭底下睡覺的大牯牛，趕它的牧童早已不知去向。
",
]));
	set("objects",([
	__DIR__"npc/frog" : 4 ,
	]) );
	set("outdoors","land");
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"ms2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
