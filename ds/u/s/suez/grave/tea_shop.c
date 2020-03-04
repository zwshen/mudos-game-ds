// Room: /u/s/suez/grave/tea_shop.c

inherit ROOM;

void create()
{
	set("short", "茶肆");
	set("long", @LONG
這是一間用茅草搭起的簡單小茶棚，茶棚旁的榕樹枝葉茂密，細碎的
陽光從樹葉間散落在四周地上，風一吹，就像灑滿一地碎琉璃一般，在搖
曳不定的光線下，你的心靈似乎又澄清了許多。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"path_10",
]));
	set("valid_startroom", "1");
	set("no_clean_up", 0);
        set("light",1);
        set("no_fight",1);
        set("no_kill",1);

	setup();
	replace_program(ROOM);
}
