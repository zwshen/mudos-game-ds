#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(BOLD+BLK"�¦����"NOR,({"black crystal","crystal"}));
  set_weight(100);
  set("no_give",1);
  set("no_put",1);
  setup();
}

int query_autoload() { return 1; }
