// taoist_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("茅山派留言板", ({ "board" }) );
	set("location", "/d/temple/temple1");
	set("board_id", "taoist_b");
	set("long",
		"這是供茅山派弟子留言記事的留言板。\n" );
	setup();
	set("capacity", 30);

}
