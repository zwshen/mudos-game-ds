// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIW"天地會留言"NOR, ({ "chat board","board" }) );
	set("location", "/open/world1/acme/area/sky/room35");
	set("board_id", "sky_room35_b");
	set("long",
		"這是一個天地會內一般性用途的留言板。\n" );
	setup();
	set("capacity", 99);
}
