

#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()

{

  set_name(HIG"Ｄ級天劍"NOR,({ "level D sword","sword" }) );

  set_weight(1500);

  if( clonep() )

    set_default_object(__FILE__);

  else

  {

    set("unit", "把");

    set("long", "這是神兵們所持的天劍。\n");

    set("material", "iron");

    set("value",2000);

    set("volume",1);

  }

  init_sword(30);

  setup();

}
