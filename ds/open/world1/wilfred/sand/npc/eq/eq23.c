#include <ansi.h>
#include <armor.h>
inherit LEGGING;
void create()
{
  set_name(HIW"銀鱗脛甲"NOR ,({ "dragon leggings","leggings" }) );
  set("long","由龍的脛部的皮所製成之脛甲，質輕耐用。");
  set_weight(1800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "雙");
    set("value",14000);
  }
  set("limit_level",25);
  set("armor_prop/armor",12);
  set("armor_prop/int",-1);
  set("armor_prop/con",2);
  set("armor_prop/dodge",10);
  set("beast_armor_prop/armor",14);
  set("beast_armor_prop/con",10);
  setup();
}
