#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIM"天地會許\願板"NOR, ({ "sky wish board","board" }) );
        set("location", "/open/world1/manto/sky2_1f/map_3_11");
        set("board_id", "sky2_1f_3_11_b");
        set("long","
這是一個天地會內提供裝備需求所用的許\願板。
需留下大名，需求物品的內容或名稱，以及截止時間等訊息。
提供者以followup方式回覆，可為提升幫會等級的依據。\n" );
        setup();
        set("capacity", 99);
}
