// skill_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("職業留言板", ({ "board" }) );
	set("location", "/d/wiz/hall_guild");
	set("board_id", "guild_b");
	set("long",
		"這是一個巫師們討論職業的留言板。\n" );
	setup();
	set("capacity", 90);

}
