#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
  set_name(HIG"¤ì¸­ÇU¦ç"NOR ,({ "mu-ie cloth","cloth" }) );
  set("long",HIC"¤ì¸­§ø§ÔªÌ©Ò¬ïªº¦çªA¡C\n"NOR);

  set_weight(2100);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "¥ó");
    set("value",1200);
  }
  set("armor_prop/armor",23);
  setup();
}
