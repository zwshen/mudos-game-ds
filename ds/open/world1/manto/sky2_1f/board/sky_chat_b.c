#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIW"天地會留言板"NOR, ({ "sky chat board","board" }) );
        set("location", "/open/world1/manto/sky2_1f/map_5_9");
        set("board_id", "sky2_1f_5_9_b");
        set("long",
                "這是一個天地會內一般性用途的留言板。\n" );
        setup();
        set("capacity", 300);
}
