#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
       set_name(HIW"幸運"HIY"屋"HIM"留言版"NOR, ({"timer board","board" }) );
        set("location","/u/s/superman/workroom.c");
        set("board_id","superman_b.c");
        set("long","有事找我嗎？有話想對我說嗎？
不論是要留訊息給我、留下你喜歡的詩文或是塗塗鴉，都可以在這板子上
盡情創作、留下痕跡，讓我知道還有你們這些關心我的朋友在我身邊。\n");
        setup();
        set("capacity", 100);
 
}
