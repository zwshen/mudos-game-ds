#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
  set_name(HIG"¤ì¸­ÇU¿Ç"NOR ,({ "mu-ie pants","pants" }) );
  set("long",HIC"¤ì¸­§ø§ÔªÌ©Ò¬ïªº¿Ç¤l¡C\n"NOR);

  set_weight(2100);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "±ø");
    set("value",1200);
  }
  set("armor_prop/armor",14);
  setup();
}
