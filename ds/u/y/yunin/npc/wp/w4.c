

#include <ansi.h>

#include <weapon.h>

inherit FORK;

void create()

{

  set_name(HIG"Ｃ級天槍"NOR,({ "level C spear","spear" }) );

  set_weight(1500);

  if( clonep() )

    set_default_object(__FILE__);

  else

  {

    set("unit", "把");

    set("long", "這是守衛們所持的天劍。\n");

    set("material", "iron");

    set("value",3100);

    set("volume",1);

  }

  init_fork(35);

  setup();

}
