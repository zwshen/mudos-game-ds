// fighter_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("武者留言板", ({ "board" }) );
	set("location", CLASS_D("fighter") + "/guildhall");
	set("board_id", "fighter_b");
	set("long",	"這是供武林中人留言記事的留言板。\n" );
	setup();
	set("capacity", 80);

}
