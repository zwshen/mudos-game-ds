#include <ansi.h>

inherit BULLETIN_BOARD;
void create()
{
        set_name( HIW"老爸"HIM"的"HIC"留"HIR"言"HIB"版"NOR, ({ "board" }) );
        set("location", "/u/d/dad/workroom");
        set("board_id", "dad_b");
        set("long",     "這是老爸的留言板，有空來灌水吧．\n" );
        setup();
        set("capacity", 40);

}

