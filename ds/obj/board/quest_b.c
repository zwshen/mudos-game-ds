// quest_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("任務留言板", ({ "board" }) );
	set("location", "/d/wiz/hall_quest");
	set("board_id", "quest_b");
	set("long",
		"這是一個巫師們討論任務與謎題的留言板。\n" );
	setup();
	set("capacity", 90);

}
