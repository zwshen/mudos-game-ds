// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("公共留言板", ({ "board" }) );
	set("location", "/open/world2/anfernee/start/hall");
	set("board_id", "login_b");
	set("long",	"這是一個供所有旅客留言討論的留言板。\n" );
	setup();
	set("capacity", 50);

}
