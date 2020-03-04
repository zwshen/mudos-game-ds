#include <ansi.h>
#include <armor.h>
inherit ANKLE;

void create()
{
  set_name(HIY"奔月腳鍊"NOR ,({ "run-moon ankle","ankle" }) );
  set("long","這是一條質地怪異的腳鍊，穿在腳踝上，好像還滿帥氣的。");
  set_weight(1800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "條");
    set("value",0);
  }
  set("armor_prop/armor",5);
  set("armor_prop/shield",5);
  set("armor_prop/str",3);
  set("armor_prop/con",3);
  set("armor_prop/int",3);
  set("armor_prop/dex",3);
  setup();
}

