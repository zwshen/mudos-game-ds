#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
  set_name(HIM"珊瑚"NOR"手環"NOR,({ "coral bracelet","bracelet" }) );
  set("long",HIW @LONG
粉紅色的漂亮珊瑚磨成手環形狀，戴在手上感覺心情很愉快。
LONG NOR);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(700);
    set("unit", "副");
    set("value",800);
    set("volume",1);
  }
  set("armor_prop/armor", 1);
  set("limit_con",10);
  set("armor_prop/con", 1);
  set("armor_prop/int", 1);
  setup();
}
