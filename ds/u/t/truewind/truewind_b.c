#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIW"¥¨¥Û"NOR, ({ "board" }) );
    set("location", "/u/t/truewind/workroom");
    set("board_id", "TR_board");
    set("long","¥¨¥Û¡C\n" );
    setup();
    set("capacity", 99);
    set("master",({ "truewind" }));
}

