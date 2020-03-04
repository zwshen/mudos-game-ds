inherit ROOM;

void create()
{
	set("short", "無相法環");
	set("long", @LONG
這裡一邊的牆上寫著大大的『相』字，而另一邊的牆上寫著：『
藥王佛十二願六願諸根完美：願我來世得菩提時，若諸有情其身下劣
，諸根不具，醜陋頑愚，盲聾瘖啞，攣躄背僂，白癩癲狂，種種病苦
；聞我名已，一切皆得端正黠慧，諸根完具，無諸疾苦。』西邊有一
扇拱門，裡面好像有一尊雕像。 
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
    		"west" : __DIR__"cir18",
  		"north" : __DIR__"cir13",
  		"southwest" : __DIR__"cir22",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
