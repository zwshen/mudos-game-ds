inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name(HIY"＝留言板＝"NOR, ({ "board" }) );
        set("location","/u/m/macs/workroom");
        set("board_id","macs_board");
        set("long","用來留言的...\n" );
        setup();
        set("capacity", 100);

}


