#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIR"聖誕"HIW"腰帶"NOR ,({ "christmas waist","waist" }) );
  set("long",@LONG
這是一條樸素的腰帶，你注意到上面的扣子竟然已經扣到最外一個了，
看樣子這是給大腰圍的胖子穿的，但不知如何，你就是想要穿上它。
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "fur");
    set("volume",2);
    set("unit", "條");
    set("value",1);
  }
  set("armor_prop/armor",1);
  setup();
}

