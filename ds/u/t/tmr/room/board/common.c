// common.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("留言板", ({ "board" }) );
	set("location", "/u/t/tmr/room/bookroom.c");
	set("board_id", "common");
	set("long",
		"這是一個供人留言記事給奇的留言板。\n");
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}
