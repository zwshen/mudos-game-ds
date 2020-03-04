#include <weapon.h>
inherit SWORD;
void create()
{
 set_name("迷你劍",({"mini sword","sword"}) );
 set_weight(3000);//damage*50就是該武器的重量
 if( clonep() )
    set_default_object(__FILE__);
 else
 {
  set("unit", "把");
  set("long",
      "劍刃只有一尺長的小劍。\n");
  set("value",10);
  set("material", "iron");
  set("wield_msg","$N將$n"+"由腰間抽出\n");
  set("unequip_msg","$N將$n"+"慢慢放回腰間。\n");
  init_sword(5);
 }
 setup();
}

