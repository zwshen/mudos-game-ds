#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("長劍",({"longsword","sword"}) );
  set("long","一把樣式普通的長劍。\n");
      set_weight(3000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","把");
        set("value",800);
        set("volume",2);
        set("material","iron");
   }
        init_sword(12);
    setup();
}
