#include <weapon.h>
inherit FORK;
void create()
{
        set_name("葬槍",({"funeral pike","pike"}) );
        set("long","一把看起來年代很遠的槍，似乎是以前武林人士陪葬的武器。\n");
          set_weight(6200);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","把");
        set("value",3500);
        set("volume",3);
        set("material","iron");
             }
  set("weapon_prop/int",2);
  set("weapon_prop/hit",6);
  init_fork(38);
  setup();
}


