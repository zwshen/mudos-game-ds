#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIR"令伊"HIW"留言板"NOR,({"orz board","board"}));
        set("location","/u/o/orzer/workroom.c");
        set("board_id", "orzer_b");
        set("long",
        "這是一塊跟令伊聯絡的版子 請多多留下建議。\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}

