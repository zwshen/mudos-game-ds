#include <ansi.h>;
inherit BULLETIN_BOARD;

void create()
{
set_name(YEL"緊急通訊網"NOR,({"119 board","board"}) );
set("location", "/u/a/aoe/workroom");
     set("board_id", "aoe_b");
  set("long","這個版子用於緊急聯絡Aoe用。\n"NOR);
        setup();
        set("capacity", 50);
        replace_program(BULLETIN_BOARD);
}
