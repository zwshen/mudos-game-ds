// mob_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("怪物留言板", ({ "board" }) );
	set("location", "/d/wiz/hall3");
	set("board_id", "mob_b");
	set("long",
		"這是一個巫師們討論怪物的留言板。\n" );
	setup();
	set("capacity", 50);

}
