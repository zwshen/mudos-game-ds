// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIW"天地會要聞板"NOR, ({ "heaven board","board" }) );
        set("location", "/open/world1/manto/sky2_2f/map_9_12");
	set("board_id", "sky_room05_b");
	set("long",
		"這是一個天地會公告會內大事用的留言板。\n" );
	setup();
	set("capacity", 99);
}
