#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name("工讀生留言板",({"board"}));
	set("location","/open/world2/obj/workroom.c");
	set("board_id", "superplayer_b");
	set("long",@LONG
這是一塊用軟木做的留言板，給臨時工讀生討論用的。
LONG);
	setup();
  	set("capacity",60);
}
