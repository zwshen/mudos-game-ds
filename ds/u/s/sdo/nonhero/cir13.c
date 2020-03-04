inherit ROOM;

void create()
{
	set("short", "無相法環");
	set("long", @LONG
這裡一邊的牆上寫著大大的『人』字，而另一邊的牆上寫著：『
藥王佛十二願五願戒行清靜：願我來世得菩提時，若有無量無邊有情
，於我法中修行梵行，一切皆令得不缺戒，具三聚戒；設有毀犯，聞
我名已，還得清靜，不墮惡趣。』 
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"south" : __DIR__"cir19",
  		"north" : __DIR__"cir9",
  		"east" : __DIR__"cir14",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
