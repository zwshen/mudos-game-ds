#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIW"海軍軍服"NOR ,({"marine cloth","cloth" }) );
  set("long",@LONG
這是以上古魔獸－劍牙巨虎之皮所製成的皮衣，不論是毛色還是
柔軟度，可說是皮衣中的極品!
LONG
);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "件");
    set("value",20000);
    set("material", "fur");
    set("limit_level",40);
    set("armor_prop/shield",10);
    set("armor_prop/str",2);
    set("armor_prop/con",2);
    set("armor_prop/dex",1);
    set("armor_prop/armor", 20);
  }
  setup();
}