#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC"天地會公告板"NOR, ({ "sky announce board","board" }) );
        set("location", "/open/world1/manto/sky2_1f/map_3_9");
        set("board_id", "sky2_1f_3_9_b");
        set("long",
                "這是一個天地會內公佈新事項或是重要消息所用的留言板。\n" );
        setup();
        set("capacity", 300);
}
