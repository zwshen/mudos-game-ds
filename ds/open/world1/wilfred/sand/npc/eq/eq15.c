#include <armor.h>
inherit MASK;
void create()
{
  set_name("紙面具" ,({ "paper mask","mask" }) );
  set("long","這是一個小孩子用來遊戲的紙面具，上面畫的是判官的臉。");
  set_weight(100);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "paper");
    set("volume",1);
    set("unit", "個");
    set("value",150);
  }
  set("armor_prop/armor",2);
  setup();
}
