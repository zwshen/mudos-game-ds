#include <path.h>
inherit ITEM;

void create()
{
  set_name("破紙張", ({"hands design page","page"}) );
  set("long", 
      "一張有點破爛的紙，紙上寫著【矢射手甲】，還有密密麻麻像是設計\n"
     +"圖的圖樣。\n"
     );
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "張");
    set("volume",1);
    set("no_sell",1);
  }
  setup(); 
}
