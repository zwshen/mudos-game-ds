// arch_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("魔神留言板", ({ "board" }) );
    set("location", "/d/wiz/hall_arch");
	set("board_id", "arch_b");
	set("long",
		"這是一個大魔神們討論與提出問題的留言板。\n" );
	setup();
	set("capacity", 90);

}
