#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name(HIG"牧神之力鍊"NOR,({"pan ankle","ankle"}));
  set("long", @LONG  
這是一串牧神潘恩的足鍊，用你從來沒有見過的植物所做成的。
LONG);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "串");
    set("volume", 3);
    set("value", 4000);
    set("material","gold");
  }
  set("limit_lv",30);
  set("armor_prop/armor", 5);
  set("armor_prop/str", 2);
  setup();
}

