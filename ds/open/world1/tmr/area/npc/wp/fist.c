#include <weapon.h>

inherit FIST;

void create()
{
    set_name("指虎",({"tiger fist","fist"}) );
   set("long","一個鐵鑄的指虎，用來打人似乎滿痛的。\n");
        set_weight(2000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","個");
            set("value",600);
        set("material","iron");
      init_fist(10);
   }
setup();
}
