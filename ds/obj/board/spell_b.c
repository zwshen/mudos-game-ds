// skill_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("法術留言板", ({ "board" }) );
	set("location", "/d/wiz/hall_spell");
	set("board_id", "spell_b");
	set("long",
		"這是一個巫師們討論法術的留言板。\n" );
	setup();
	set("capacity", 90);

}
