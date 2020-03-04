#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
  set_name("墳墓", ({"tomb"}) );
  set("long",@LONG
一座墳墓，墳墓四周整理打掃的相當乾淨，墓碑上寫著【日向．霧子】
之墓。
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("no_sac",1);
    set("unit", "座");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}
