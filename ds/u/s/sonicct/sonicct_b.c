#include <ansi.h>

inherit BULLETIN_BOARD;
void create()
{
  set_name(HIR"神風留言板"NOR,({"board"}));
  set("location","/u/s/sonicct/workroom.c");
  set("board_id", "sonicct_b");
  set("long",
    "這是一塊留言板。\n");
  setup();
  set("capacity",100);
   replace_program(BULLETIN_BOARD);
}
