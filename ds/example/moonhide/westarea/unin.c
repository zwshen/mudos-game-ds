#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIG"元"HIW"魂", ({"unin soul"}) );
  set("long",@LONG
九天雲魂的菜鳥。
LONG
);
  set("race", "human");
  set("unit","隻"); 
  set("title",HIR"九天雲魂");    set("age",230);
  set("level",26);
  setup();
  add_money("coin",200);
}

