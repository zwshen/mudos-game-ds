#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name("阿羅漢束帶",({"A-luo-han waist","waist"}));
  set("long", @LONG
這是一條上頭用梵文字寫滿了金剛經文的束帶。
LONG);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "條");
    set("volume",2);
    set("value",5000);
    set("material","fur");
  }
  set("limit_lv",25);
  set("armor_prop/armor",10);
  set("armor_prop/shield",10);
  setup();
}

